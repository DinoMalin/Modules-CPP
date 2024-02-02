#ifndef CONTACT
# define CONTACT

# include <iostream>
# include <string>

class Contact {
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
	public:
		Contact();
		void		print(std::ostream &flux) const;
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickName() const;
		void		setFirstName(std::string str);
		void		setLastName(std::string str);
		void		setNickname(std::string str);
		void		setPhoneNumber(std::string str);
		void		setDarkestSecret(std::string str);
};

std::ostream		&operator<<(std::ostream &flux, Contact const& contact);

#endif