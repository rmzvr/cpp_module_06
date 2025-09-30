#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base *generate(void)
{
	std::random_device				rd;
	std::mt19937					gen(rd());
	std::uniform_int_distribution<>	distrib(0, 2);

	int	random_value = distrib(gen);

	switch (random_value)
	{
	case 0:
		return new A;
		break;
	case 1:
		return new B;
		break;
	case 2:
		return new C;
		break;
	default:
		return nullptr;
		break;
	}
}

void identify(Base *p)
{
	std::cout << "Dynamically identified instance by pointer: ";
	if (dynamic_cast<A *>(p) != nullptr)
	{
		std::cout << "A\n";
	}
	else if (dynamic_cast<B *>(p) != nullptr)
	{
		std::cout << "B\n";
	}
	else if (dynamic_cast<C *>(p) != nullptr)
	{
		std::cout << "C\n";
	}
	else
	{
		std::cout << "Unknown\n";
	}
}

void identify(Base &p)
{
	std::cout << "Dynamically identified instance by reference:\n";
	try
	{
		A &	a = dynamic_cast<A &>(p);
		std::cout << "Is A: " << &a << std::endl;
	}
	catch(...)
	{
		std::cout << "Not A\n";
	}
	try
	{
		B &	b = dynamic_cast<B &>(p);
		std::cout << "Is B: " << &b << std::endl;
	}
	catch(...)
	{
		std::cout << "Definitely not B\n";
	}
	try
	{
		C &	c = dynamic_cast<C &>(p);
		std::cout << "Is C: " << &c << std::endl;
	}
	catch(...)
	{
		std::cout << "Not C\n";
	}
}
