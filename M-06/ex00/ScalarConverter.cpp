#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &ref) {*this = ref;};
const ScalarConverter& ScalarConverter::operator=(const ScalarConverter &ref) {(void)ref; return *this;}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal) {
	std::string	toChar;
	int			toInt;
	float		toFloat;
	double		toDouble;

	std::string pseudoLiterals[] = {"-inff", "+inff", "-inf", "+inf", "nan"};
	bool isPseudoLiteral(false);

	toInt = atoi(literal.c_str());
	toFloat = static_cast<float>(atof(literal.c_str()));
	toDouble = atof(literal.c_str());

	if (toInt >= 32 && toInt <= 126) {
		toChar = "'";
		toChar += static_cast<char>(toInt);
		toChar += "'";
	} else
		toChar = "Non displayable";

	for (int i = 0; i < 5; i++) {
		if (pseudoLiterals[i] == literal)
			isPseudoLiteral = true;
	}

	if (!isPseudoLiteral && toInt == 0 && literal[0] != 0 && literal[1] != 0 && literal[0] != '+' && literal[0] != '-') {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}

	if (isPseudoLiteral) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "char: " << toChar << std::endl;
		std::cout << "int: " << toInt << std::endl;
	}

	if (toFloat - static_cast<int>(toFloat) == 0) {
		std::cout << "float: "<< toFloat << ".0f" << std::endl;
		std::cout << "double: "<< toDouble << ".0" << std::endl;
	} else {
		std::cout << "float: "<< toFloat << "f" << std::endl;
		std::cout << "double: "<< toDouble << std::endl;
	}
}