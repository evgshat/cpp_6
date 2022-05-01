#include "Base.hpp"

Base* generate(void)
{
	srand(time(0));
	int x = rand() % 3 + 1;
	if (x == 1) return (new A());
	if (x == 2) return (new B());
	if (x == 3) return (new C());
	return (0);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "It`s A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "It`s B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "It`s C" << std::endl;
	else
		std::cout << "This class not found" << std::endl;
}

void identify(Base& p)
{
	bool flag = false;

	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "It`s A" << std::endl;
		flag = true;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	//
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "It`s B" << std::endl;
		flag = true;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	//
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "It`s C" << std::endl;
		flag = true;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	if (!flag)
		std::cout << "This class not found" << std::endl;
}
