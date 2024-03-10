#pragma once
#include <map>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>


class BitcoinExchange {
	private:
		std::map<std::string, double> data;
		std::map<std::string, std::string> input;

		double	getValue(std::string date);
		void	checkExceptions(std::string date, std::string value);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &ref);
		~BitcoinExchange();

		const BitcoinExchange &operator=(const BitcoinExchange &ref);

		void	fillData(std::string file);
		void	fillInput(std::string file);
		void	compare();

		class WrongFileException : public std::exception {
			public:
				const char *what() const throw() {return "Unable to open file";}
		};
		class WrongDateException : public std::exception {
			public:
				const char *what() const throw() {return "Date is incorrectly formated";}
		};
		class OldDateException : public std::exception {
			public:
				const char *what() const throw() {return "Date is too old";}
		};
		class NegativeValueException : public std::exception {
			public:
				const char *what() const throw() {return "Negative number is not correct";}
		};
		class TooLargeException : public std::exception {
			public:
				const char *what() const throw() {return "Too large number";}
		};
		class EmptyFieldException : public std::exception {
			public:
				const char *what() const throw() {return "Empty field";}
		};
};

std::string getString(int date);
int getIntDate(std::string dateStr);