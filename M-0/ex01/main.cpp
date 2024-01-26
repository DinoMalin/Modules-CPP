#include <iostream>
#include <string>
#include "Phonebook.hpp"

int getInput(std::string prompt, std::string &result) {
	std::cout << prompt;
	std::cin >> result;
	if (result.empty()) {
		std::cout << "A contact can't have empty fields !" << std::endl;
		return 0;
	}
	return 1;
}

void	search(Phonebook &phonebook) {
	if (phonebook.getIndex() < 0) {
		std::cout << "The phonebook is empty." << std::endl;
		return ;
	}
	std::string	index;
	std::cout << phonebook << std::endl;
	while (true) {
		std::cout << "Enter a valid index : ";
		std::cin >> index;
		if (index.length() > 1 || !isdigit(index[0]) || index[0] - '0' > phonebook.getIndex())
			std::cout << "Invalid index !" << std::endl;
		else {
			phonebook.printContact((int)(index[0] - '0'));
			return ;
		}
	}
}

void	add(Phonebook &phonebook) {
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout << "<---------- ADD ---------->" << std::endl << std::endl;
	if (!getInput("First name : ", firstName))
		return ;
	if (!getInput("Last name : ", lastName))
		return ;
	if (!getInput("Nickname : ", nickname))
		return ;
	if (!getInput("Phone number : ", phoneNumber))
		return ;
	if (!getInput("Darkest Secret : ", darkestSecret))
		return ;
	phonebook.add(firstName, lastName, nickname, phoneNumber, darkestSecret);
	return ;
}

void help() {
	std::cout << "ERROR : INSTRUCTION DOES NOT EXIST" << std::endl << std::endl;
	std::cout << "############# HELP #############" << std::endl;
	std::cout << "- ADD\t: Add a contact to the phonebook." << std::endl;
	std::cout << "- SEARCH\t: Search a contact in the phonebook." << std::endl;
	std::cout << "- EXIT\t: Exit the phonebook." << std::endl << std::endl;
}

int main() {
	Phonebook phonebook;
	std::string instruction("NULL");

	while (true) {
		std::cout << "Enter an instruction : ";
		std::cin >> instruction;
		if (instruction == "ADD")
			add(phonebook);
		else if (instruction == "SEARCH")
			search(phonebook);
		else if (instruction == "EXIT")
			return (0);
		else
			help();
	}
	return (0);
}

