#ifndef PHONEBOOK
# define PHONEBOOK

# include <iostream>
# include <string>
# include "Contact.hpp"

class Phonebook
{
	public:
		Phonebook();
		void	print(std::ostream &flux) const;
		void	search(int index);
		void	add(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret);
		int		getIndex();
		void	printContact(int index);
	private:
		int		index;
		Contact	contacts[8];
};

std::ostream	&operator<<(std::ostream &flux, Phonebook const& phonebook);
std::string		getStringToDisplay(std::string str);

#endif