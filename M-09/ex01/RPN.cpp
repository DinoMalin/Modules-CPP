#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &ref) {*this = ref;}
RPN::~RPN() {}

const RPN& RPN::operator=(const RPN &ref) {
	this->numbers = ref.numbers;
	return *this;
}

bool strIsDigit(std::string str) {
	if (str.length() > 1 && !isdigit(str[1]) && (str[0] == '-' || str[0] == '+'))
		return false;
	if (!isdigit(str[0]) && str[0] != '-' && str[0] != '+')
		return false;

	int dot(0);
	for (int i = 1; i < static_cast<int>(str.length()); i++) {
		if (str[i] == '.')
			dot++;
		if ((!isdigit(str[i]) && str[i] != '.') || dot > 1)
			return false;
	}
	return true;
}

RPN::RPN(const std::string &str) {
	std::stringstream stream(str);
	std::string word;

	while (stream >> word) {
		if (word == "+" || word == "-" || word == "*" || word == "/") {
			if (this->numbers.size() < 2)
				throw BadFormatException();
			doOperation(word);
		}
		else if (strIsDigit(word))
			this->numbers.push(atof(word.c_str()));
		else
			throw UnexpectedCharacterException();
	}

	if (this->numbers.size() != 1)
		throw BadFormatException();
}

void RPN::doOperation(std::string op) {
	double b = numbers.top();
	numbers.pop();
	double a = numbers.top();
	numbers.pop();

	if (op == "+")
		numbers.push(a + b);
	else if (op == "-")
		numbers.push(a - b);
	else if (op == "*")
		numbers.push(a * b);
	else if (op == "/") {
		if (b == 0)
			throw DivisionByZeroException();
		numbers.push(a / b);
	}
}

double RPN::getResult() {
	return this->numbers.top();
}