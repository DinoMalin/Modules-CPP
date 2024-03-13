#pragma once
#include <vector>
#include <algorithm>

class Span {
	private:
		unsigned int max;
		std::vector<int> vect;
	public:
		Span();
		Span(unsigned int max);
		Span(const Span &ref);
		~Span();

		const Span &operator=(const Span &ref);

		void addNumber(int n);
		void addRange(std::vector<int>::iterator start, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();
		class NoSpaceLeftException : public std::exception {
			public:
				const char *what() const throw() {return "No space left.";}
		};
		class RangeTooBigException : public std::exception {
			public:
				const char *what() const throw() {return "Range too big.";}
		};
		class NoSpanException : public std::exception {
			public:
				const char *what() const throw() {return "Not enough numbers to calculate a span.";}
		};
};