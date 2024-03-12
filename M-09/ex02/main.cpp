#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av) {
    std::string input;

    if (ac < 2) {
        std::cout << "Usage: ./PmergeMe <args>" << std::endl;
        return 1;
    }
    for (int i = 1; i < ac; i++) {
        input += av[i];
        input += " ";
    }
    try {
        PmergeMe pmm(input);
        pmm.sort();
        pmm.displayPerfs();
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << "." << std::endl;
    }
}