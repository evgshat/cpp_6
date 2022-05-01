#include "Base.hpp"

int main()
{
	Base *base = generate();
	Base &refBase = *base;
	std::cout << "base : ";
	identify(base);
	std::cout << "refBase  : ";
	identify(refBase);

	std::cout << "By base: ";
	identify(NULL);
	std::cout << "By refBasef: ";
	identify(0);
	return (0);
}
