#include <iostream>

int main()
{
	std::string	string("HI THIS IS BRAIN");
	std::string *stringPtr(&string);
	std::string &stringRef(string);

	std::cout << "Memory address of string : " << &string << std::endl;
	std::cout << "Memory address held by stringPtr : " << stringPtr << std::endl;
	std::cout << "Memory address held by stringRef : " << &stringRef << std::endl;

	std::cout << std::endl;

	std::cout << "Value of string : " << string << std::endl;
	std::cout << "Value pointed to by stringPtr : " << *stringPtr << std::endl;
	std::cout << "Value pointed to by stringRef : " << stringRef << std::endl;
}