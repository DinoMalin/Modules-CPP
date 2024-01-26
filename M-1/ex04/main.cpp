#include <iostream>
#include <fstream>
#include <string>


std::string searchAndReplace(std::string file, const std::string& s1, const std::string& s2) {
	size_t i(0);
	size_t j(0);
	std::string result("");

	while ((i = file.find(s1, i)) != std::string::npos) {
		result += file.substr(j, i - j);
		result += s2;
		i += s1.length();
		j = i;
	}
	result += file.substr(j);

	return result;
}

std::string getFile(std::ifstream &file) {
	std::string result("");
	std::string newLine("");

	while (getline(file, newLine))
		result = result + newLine + "\n";

	return result;
}
int	error_handler(int error_code) {
	if (error_code == 1)
		std::cout << "Error : Unexpected input." << std::endl;
	else if (error_code == 2)
		std::cout << "Error : Wrong file name." << std::endl;
	return 1;
}

int main(int ac, char **av) {
	if (ac != 4)
		return error_handler(1);

	std::ifstream	input;
	input.open(av[1]);
	if (!input)
		return error_handler(2);

	std::string		file(getFile(input));
	std::string		newFile(searchAndReplace(file, av[2], av[3]));

	std::ofstream	output;
	output.open(av[1]);
	if (!output)
		return error_handler(2);
	output << newFile;

	return 0;
}