#pragma once
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack< T, std::deque<T> > {
	public:
		MutantStack();
		MutantStack(const MutantStack &ref);
		~MutantStack();
		const MutantStack &operator=(const MutantStack &ref);

		typedef typename std::deque<T>::iterator iterator;

		typename std::deque<T>::iterator begin();
		typename std::deque<T>::iterator end();
};