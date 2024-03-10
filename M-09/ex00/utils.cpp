#include "BitcoinExchange.hpp"

std::string getString(int date) {
	std::stringstream ss;
	std::string result;
	ss << date;
	result = ss.str();
	return result.insert(4, "-").insert(7, "-");
}

int getIntDate(std::string dateStr) {
	int firstHyphen = dateStr.find("-");
	int secondHyphen = dateStr.find("-", firstHyphen + 1) - 1;

	dateStr.erase(firstHyphen, 1);
	dateStr.erase(secondHyphen, 1);

	return atoi(dateStr.c_str());
}