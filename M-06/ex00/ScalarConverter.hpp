#pragma once
#include <string>
#include <cstdlib>
#include <iostream>

class ScalarConverter {
	public:
		~ScalarConverter();
		static void convert(const std::string &literal);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &ref);
		const ScalarConverter &operator=(const ScalarConverter &ref);
};