#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref) {*this = ref;}
BitcoinExchange::~BitcoinExchange() {}

const BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &ref) {
	this->data = ref.data;
	return *this;
}

void BitcoinExchange::fillData(const char *file) {
	std::ifstream input;

	input.open(file);
	if (!input)
		throw WrongFileException();

	std::string line;
	while (getline(input, line)) {
		std::string date = line.substr(0, line.find(","));
		std::string value = line.substr(line.find(",") + 1, line.length()).c_str();
		if (date != "date" && line.length())
			this->data[date] = atof(value.c_str());
	}
}

void BitcoinExchange::compare(const char *fileName) {
	std::ifstream input;

	input.open(fileName);
	if (!input)
		throw WrongFileException();

	std::string line;
	while (getline(input, line)) {
		std::stringstream ss(line);
		std::string date;
		std::string value;
	
		ss >> date;
		ss >> value;
		ss >> value;

		if (value == "|")
			value = "";
		if (date == "date" || !line.length())
			continue;
		try {
			checkExceptions(date, value);
			double coeff(getValue(date));
			std::cout << date << " => "
			<< value << " = " << std::atof(value.c_str()) * coeff
			<< std::endl;
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << " => "
			<< line << std::endl;
		}
	}
}

void BitcoinExchange::checkExceptions(std::string date, std::string value) {
	int firstHyphen = date.find("-");
	int secondHyphen = date.find("-", firstHyphen + 1);

	int year = std::atoi(date.substr(0, firstHyphen).c_str());
	int month = std::atoi(date.substr(firstHyphen + 1, secondHyphen).c_str());
	int day = std::atoi(date.substr(secondHyphen + 1, date.length()).c_str());

	if (year <= 0 || month <= 0 || day <= 0)
		throw WrongDateException();

	if (!date.length() || !value.length())
		throw EmptyFieldException();

	if (month > 12)
		throw WrongDateException();
	if (day > 30 && month % 2 == 0)
		throw WrongDateException();
	if (day > 31 && month % 2 == 1)
		throw WrongDateException();
	if (day > 29 && month == 2)
		throw WrongDateException();
	if (day > 28 && month == 2 && year % 4 != 0)
		throw WrongDateException();

	long lvalue = std::atol(value.c_str());
	if (lvalue < 0)
		throw NegativeValueException();
	if (value.length() > 13 || lvalue > 1000)
		throw TooLargeException();

	for (int i = 0; size_t(i) < value.length(); i++) {
		if (!isdigit(value[i]) && value[i] != '.')
			throw UnexpectedCharacterException();
	}

	int nbMinus(0);
	for (int i = 0; size_t(i) < date.length(); i++) {
		if (!isdigit(date[i]) && date[i] != '-')
			throw UnexpectedCharacterException();
		if (date[i] == '-')
			nbMinus++;
	}

	if (nbMinus != 1)
		throw UnexpectedCharacterException();
}

double BitcoinExchange::getValue(std::string date) {
	bool valid(false);

	int dateInput(getIntDate(date));
	if (dateInput < getIntDate(this->data.begin()->first))
		throw OldDateException();

	while (!valid) {
		try {
			this->data.at(getString(dateInput));
			valid = true;
		}
		catch (std::exception &) {dateInput--;}
	}

	return this->data[getString(dateInput)];
}
