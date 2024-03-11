#pragma once
#include <deque>
#include <list>
#include <string>
#include <sstream>

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

		class BadInputException : public std::exception {
			public:
				const char *what() const throw() {return "Bad input";}
		};
};