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
	for (int i(0); i < str.length(); i++) {
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

PmergeMe::PmergeMe(const std::string &str) {
	std::stringstream ss;
	std::string num;

	while (ss >> num) {
		if (!isDigitStr(num))
			throw BadInputException();
		deq.push_back(atoi(num.c_str()));
		list.push_back(atoi(num.c_str()));
	}
}

template<typename T>
std::vector<std::pair<int, int>> getPairs(T container) {
	std::vector<std::pair<int, int>> result;

	for (T::iterator it = container.begin(), int i = 0; it != container.end() && it != container.end(); it++, i++;) {
		if (i % 2 == 0 && i != container.size() - 1) {
			std::pair<int, int> pair;

			pair.first = *it;
			pair.second = *(it + 1);
			result.push_back(pair);
		}
	}

	for (int i = 0; i < result.size(); i++) {
		if (result[i].first < result[i].second)
			std::swap(result[i].first, result[i].second);
	}

	return result;
}

void PmergeMe::sortDeq() {
	std::vector<std::pair<int, int>> pairs = getPairs(this->deq);

	// sortPairs();
	// insertPairs();
}