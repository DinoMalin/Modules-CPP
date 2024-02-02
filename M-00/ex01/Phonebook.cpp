#include "Phonebook.hpp"

Phonebook::Phonebook() {
	this->index = -1;
}

std::ostream &operator<<(std::ostream &flux, Phonebook const& phonebook) {
	phonebook.print(flux);
	return flux;
}

void Phonebook::print(std::ostream &flux) const {
	std::cout << std::endl << "<------------------- CONTACTS ------------------->" << std::endl;
	for (int i = 0; i <= this->index; i++) {
		flux << (char)(i + '0') << "         " << " | ";
		flux << getStringToDisplay(this->contacts[i].getFirstName());
		flux << " | ";
		flux << getStringToDisplay(this->contacts[i].getLastName());
		flux << " | ";
		flux << getStringToDisplay(this->contacts[i].getNickName());
		flux << std::endl;
	}
}

void Phonebook::search(int index) {
	if (index > this->index || index < 0)
		std::cout << "This contact does not exist." << std::endl;
	else
		std::cout << contacts[index] << std::endl;
}

void Phonebook::add(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret) {
	if (this->index < 7)
		this->index++;
	contacts[this->index].setFirstName(firstName);
	contacts[this->index].setLastName(lastName);
	contacts[this->index].setNickname(nickname);
	contacts[this->index].setPhoneNumber(phoneNumber);
	contacts[this->index].setDarkestSecret(darkestSecret);
}

void Phonebook::printContact(int index) {
	std::cout << "<---------- CONTACT #" << index << " ---------->" << std::endl;
	std::cout << contacts[index];
}

int Phonebook::getIndex() {
	return this->index;
}

std::string	getStringToDisplay(std::string str) {
	std::string result;

	if (str.length() > 10)
		return str.substr(0, 9) + '.';
	else
		result = str;
	for (int i = str.length(); i < 10; i++)
		result += ' ';
	return result;
}