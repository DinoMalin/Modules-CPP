#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &ref) {*this = ref;}
PmergeMe::~PmergeMe() {}

const PmergeMe& PmergeMe::operator=(const PmergeMe &ref) {
	this->deq = ref.deq;
	this->list = ref.list;
	return *this;
}

bool isDigitStr(std::string str) {
	for (int i(0); size_t(i) < str.length(); i++) {
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

bool isInt(std::string num) {
	if (num.length() > 10 || atol(num.c_str()) > 2147483647)
		return false;
	return true;
}

PmergeMe::PmergeMe(const std::string &input) {
	std::stringstream ss(input);
	std::string num;

	this->input = input;

	while (ss >> num) {
		if (!isDigitStr(num) || !isInt(num))
			throw BadInputException();
		deq.push_back(atoi(num.c_str()));
		list.push_back(atoi(num.c_str()));
	}

	this->size = deq.size();
}

pairVector PmergeMe::getPairsDeq() {
	pairVector result;
	int i(0);

	for (std::deque<int>::iterator it = this->deq.begin(); it != this->deq.end(); it++) {
		if (i % 2 == 0 && size_t(i) != this->deq.size() - 1) {
			std::pair<int, int> pair;

			pair.first = *it;
			pair.second = *(it + 1);
			result.push_back(pair);
		} else if (i % 2 == 0 && size_t(i) == this->deq.size() - 1)
			this->last = *it;
		i++;
	}

	for (int i = 0; size_t(i) < result.size(); i++) {
		if (result[i].first < result[i].second)
			std::swap(result[i].first, result[i].second);
	}

	return result;
}

pairVector PmergeMe::getPairsList() {
	pairVector result;

	int i(0);
	for (std::list<int>::iterator it = this->list.begin(); it != this->list.end(); it++) {
		if (i % 2 == 0 && size_t(i) != this->list.size() - 1) {
			std::pair<int, int> pair;
			pair.first = *it;
			it++; pair.second = *it; it--;
			result.push_back(pair);
		} else if (i % 2 == 0 && size_t(i) == this->list.size() - 1) {
			this->last = *it;
		}
		i++;
	}

	for (int i = 0; size_t(i) < result.size(); i++) {
		if (result[i].first < result[i].second)
			std::swap(result[i].first, result[i].second);
	}

	return result;
}

pairVector createPairVector(pairVector::iterator begin, pairVector::iterator end) {
	pairVector result;
	for (pairVector::iterator it = begin; it != end; it++) {
		result.push_back(*it);
	}
	return result;
}

void sortPairs(pairVector &pairs) {
	if (pairs.size() <= 1)
		return ;

	pairVector::iterator middle = pairs.end() - pairs.size() / 2;
	pairVector beginHalf = createPairVector(pairs.begin(), middle);
	pairVector endHalf = createPairVector(middle, pairs.end());

	sortPairs(beginHalf);
	sortPairs(endHalf);

	size_t beginIndex(0);
	size_t endIndex(0);
	size_t	idx(0);

	while (beginIndex < beginHalf.size() && endIndex < endHalf.size()) {
		if (beginHalf[beginIndex].first < endHalf[endIndex].first)
			pairs[idx++] = beginHalf[beginIndex++];
		else
			pairs[idx++] = endHalf[endIndex++];
	}

	while (beginIndex < beginHalf.size()) {
		pairs[idx++] = beginHalf[beginIndex++];
	}

	while (endIndex < endHalf.size()) {
		pairs[idx++] = endHalf[endIndex++];
	}
}

std::vector<int> getInsertionOrder(int size) {
	std::vector<int> jacobsthalSeq;
	jacobsthalSeq.push_back(1);
	jacobsthalSeq.push_back(3);

	for (int i = 2; i < size; i++) {
		jacobsthalSeq.push_back(jacobsthalSeq[i - 1] + 2 * jacobsthalSeq[i - 2]);
	}

	std::vector<int> result;
	for (int i = 1; i < size; i++) {
		if (std::find(result.begin(), result.end(), i) != result.end())
			continue;
		result.push_back(i);
		std::vector<int>::iterator jacobsthalIdx(std::lower_bound(jacobsthalSeq.begin(), jacobsthalSeq.end(), i + 1));
		if (*jacobsthalIdx < size) {
			result.push_back(*jacobsthalIdx);
			jacobsthalSeq.erase(jacobsthalIdx);
		}
	}

	return result;
}

void PmergeMe::insertPairsDeq(pairVector &pairs) {
	deq.clear();
	deq.push_back(pairs[0].second);

	for (int i = 0; size_t(i) < pairs.size(); i++) {
		deq.push_back(pairs[i].first);
	}

	std::vector<int> insertionOrder(getInsertionOrder(deq.size() - 1));
	for (int i = 0; size_t(i) < pairs.size() - 1; i++) {
		deq.insert(std::lower_bound(deq.begin(), deq.end(), pairs[insertionOrder[i]].second), pairs[insertionOrder[i]].second);
	}
	if (size % 2 == 1)
		deq.insert(std::lower_bound(deq.begin(), deq.end(), this->last), this->last);
}

void PmergeMe::sortDeq() {

	if (this->size != 1) {
		pairVector pairs = getPairsDeq();
		sortPairs(pairs);
		insertPairsDeq(pairs);
	}
}

void PmergeMe::insertPairsList(pairVector &pairs) {
	list.clear();
	list.push_back(pairs[0].second);

	for (int i = 0; size_t(i) < pairs.size(); i++) {
		list.push_back(pairs[i].first);
	}

	std::vector<int> insertionOrder(getInsertionOrder(list.size() - 1));

	for (int i = 0; size_t(i) < pairs.size() - 1; i++) {
		list.insert(std::lower_bound(list.begin(), list.end(), pairs[insertionOrder[i]].second), pairs[insertionOrder[i]].second);
	}
	if (size % 2 == 1)
		list.insert(std::lower_bound(list.begin(), list.end(), this->last), this->last);
}

void PmergeMe::sortList() {
	if (this->size != 1) {
		pairVector pairs = getPairsList();
		sortPairs(pairs);
		insertPairsList(pairs);
	}
}

void PmergeMe::sort() {
	std::clock_t startDeq = std::clock();
	this->sortDeq();
	std::clock_t endDeq = std::clock();

	std::clock_t startList = std::clock();
	this->sortList();
	std::clock_t endList = std::clock();

	this->timeDeq = 1000.0 * (endDeq - startDeq);
	this->timeList = 1000.0 * (endList - startList);
}

void PmergeMe::displayPerfs() {
	std::cout << "Before: " << this->input << std::endl;
	std::cout << "After:  ";

	for (int i = 0; size_t(i) < deq.size(); i++) {
		std::cout << this->deq[i];
		if (size_t(i) != deq.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << deq.size()
	<< " with std::deque : " << std::fixed << std::setprecision(2)
	<< 1000.0 * this->timeDeq / CLOCKS_PER_SEC
	<< std::endl;
	std::cout << "Time to process a range of " << deq.size()
	<< " with std::list  : " << std::fixed << std::setprecision(2)
	<< 1000.0 * this->timeList / CLOCKS_PER_SEC
	<< std::endl;
}