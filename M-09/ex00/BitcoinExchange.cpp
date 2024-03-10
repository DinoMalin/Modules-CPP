#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref) {*this = ref;}
BitcoinExchange::~BitcoinExchange() {}

const BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &ref) {
	this->data = ref.data;
	return *this;
}

void BitcoinExchange::fillData(std::string file) {
	std::ifstream input;

	input.open(file.c_str());
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
void BitcoinExchange::fillInput(std::string file) {
	std::ifstream input;

	input.open(file.c_str());
	if (!input)
		throw WrongFileException();

	std::string line;
	while (getline(input, line)) {
		std::stringstream stream(line);

		std::string date;
		std::string value;
		stream >> date;
		stream >> value;
		stream >> value;
		if (date != "date" && line.length())
			this->input[date] = value;
	}
}

void BitcoinExchange::checkExceptions(std::string date, std::string value) {
	int firstHyphen = date.find("-");
	int secondHyphen = date.find("-", firstHyphen + 1);

	int year = std::atoi(date.substr(0, firstHyphen).c_str());
	int month = std::atoi(date.substr(firstHyphen + 1, secondHyphen).c_str());
	int day = std::atoi(date.substr(secondHyphen + 1, date.length()).c_str());

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
	if (value.length() > 13 || lvalue > 2147483647)
		throw TooLargeException();
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

void BitcoinExchange::compare() {
	for (std::map<std::string, std::string>::iterator it(this->input.begin()); it != input.end(); it++) {
		try {
			checkExceptions(it->first, it->second);
			int coeff(getValue(it->first));
			std::cout << it->first << " => "
			<< it->second << " = " << std::atof(it->second.c_str()) * coeff
			<< std::endl;
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << " => "
			<< it->first << " | " << it->second
			<< std::endl;
		}
	}
}
