#include "Harl.hpp"

int main(void)
{
	Harl harl;

	harl.complain("ERROR");
	harl.complain("DEBUG");
	harl.complain("WARNING");
	harl.complain("INFO");

	return 0;
}