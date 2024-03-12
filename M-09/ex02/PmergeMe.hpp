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

		pairVector getPairsDeq();
		pairVector getPairsList();
		void sortPairs(pairVector &pairs);
		void insertPairsDeq(pairVector &pairs);
		void insertPairsList(pairVector &pairs);
		void sortDeq();
		void sortList();
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &ref);
		PmergeMe(const std::string &str);
		~PmergeMe();

		const PmergeMe &operator=(const PmergeMe &ref);

		void sort();
		void displayPerfs();

		class BadInputException : public std::exception {
			public:
				const char *what() const throw() {return "Bad input";}
		};
};

bool isInt(std::string str);
bool isDigitStr(std::string str);
std::vector<int> getInsertionOrder(int size);
pairVector createPairVector(pairVector::iterator begin, pairVector::iterator end);