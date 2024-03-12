#include "PmergeMe.hpp"

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

pairVector createPairVector(pairVector::iterator begin, pairVector::iterator end) {
	pairVector result;
	for (pairVector::iterator it = begin; it != end; it++) {
		result.push_back(*it);
	}
	return result;
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