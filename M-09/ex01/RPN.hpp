#pragma once
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>

class RPN {
	private:
		std::stack<double> numbers;

		void doOperation(std::string op);
	public:
		RPN();
		RPN(const std::string &str);
		RPN(const RPN &ref);
		~RPN();

		const RPN &operator=(const RPN &ref);

		double getResult();

		class UnexpectedCharacterException : public std::exception {
			public:
				const char *what() const throw() {return "Unexpected character.";}
		};
		class BadFormatException : public std::exception {
			public:
				const char *what() const throw() {return "Bad format.";}
		};
		class DivisionByZeroException : public std::exception {
			public:
				const char *what() const throw() {return "Division by zero is impossible.";}
		};
};