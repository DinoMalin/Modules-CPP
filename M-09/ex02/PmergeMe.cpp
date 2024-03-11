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
