#pragma once
#include <deque>
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ctime>

typedef std::vector< std::pair<int, int> > pairVector;

class PmergeMe {
	private:
		std::deque<int> deq;
		std::list<int> list;

		std::string input;

		int last;
		int size;

		double timeDeq;
		double timeList;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &ref);
		PmergeMe(const std::string &str);
		~PmergeMe();

		const PmergeMe &operator=(const PmergeMe &ref);

		pairVector getPairsDeq();
		pairVector getPairsList();
		void insertPairsDeq(pairVector &pairs);
		void insertPairsList(pairVector &pairs);
		void sortDeq();
		void sortList();
		void sort();
		void displayPerfs();
		class BadInputException : public std::exception {
			public:
				const char *what() const throw() {return "Bad input";}
		};
};