#include "Contact.hpp"

Contact::Contact() {
	this->firstName = "";
	this->lastName = "";
	this->nickname = "";
	this->phoneNumber = "";
	this->darkestSecret = "";
}

std::ostream &operator<<(std::ostream &flux, Contact const& contact) {
	contact.print(flux);
	return flux;
}

void Contact::print(std::ostream &flux) const {
	flux << "FIRST NAME : " << this->firstName << std::endl;
	flux << "LAST NAME : " << this->lastName << std::endl;
	flux << "NICKNAME : " << this->nickname << std::endl;
	flux << "PHONE NUMBER : " << this->phoneNumber << std::endl << std::endl;
}

std::string Contact::getFirstName() const {
	return this->firstName;
}

std::string Contact::getLastName() const {
	return this->lastName;
}

std::string Contact::getNickName() const {
	return this->nickname;
}

void Contact::setFirstName(std::string str) {
	this->firstName = str;
}

void Contact::setLastName(std::string str) {
	this->lastName = str;
}

void Contact::setNickname(std::string str) {
	this->nickname = str;
}

void Contact::setPhoneNumber(std::string str) {
	this->phoneNumber = str;
}

void Contact::setDarkestSecret(std::string str) {
	this->darkestSecret = str;
}