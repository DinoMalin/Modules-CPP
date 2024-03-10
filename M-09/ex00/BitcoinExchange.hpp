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

		double	getValue(std::string date);
		void	checkExceptions(std::string date, std::string value);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &ref);
		~BitcoinExchange();

		const BitcoinExchange &operator=(const BitcoinExchange &ref);

		void	fillData(const char *file);
		void	compare(const char *file);

		class WrongFileException : public std::exception {
			public:
				const char *what() const throw() {return "Unable to open file";}
		};
		class WrongDateException : public std::exception {
			public:
				const char *what() const throw() {return "Date does not exist";}
		};
		class OldDateException : public std::exception {
			public:
				const char *what() const throw() {return "Date is too old";}
		};
		class NegativeValueException : public std::exception {
			public:
				const char *what() const throw() {return "not a positive number";}
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