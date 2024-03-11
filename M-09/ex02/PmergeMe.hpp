#pragma once
#include <deque>
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>

class PmergeMe {
	private:
		std::deque<int> deq;
		std::list<int> list;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &ref);
		PmergeMe(const std::string &str);
		~PmergeMe();

		const PmergeMe &operator=(const PmergeMe &ref);

		void sortDeq();
		class BadInputException : public std::exception {
			public:
				const char *what() const throw() {return "Bad input";}
		};
};