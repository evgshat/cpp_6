#include "Conversion.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Args wrong" << std::endl;
		exit (0);
	}
	else
	{
		Conversion ch(av[1]);
	}
}
