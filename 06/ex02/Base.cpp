#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	std::cout << "Base destructor" << std::endl;
}

Base *Base::generate(void)
{
	Base *base;
	srand(time(NULL));
	int random = rand() % 3;
	random == 0 ? base = new A() : random == 1 ? base = new B() : base = new C();
	return (base);
}

void Base::identify(Base *p)
{
	std::cout << (dynamic_cast<A *>(p) ? "A" : dynamic_cast<B *>(p) ? "B" : dynamic_cast<C *>(p) ? "C" : "Unknown") << std::endl;
}

void Base::identify(Base &p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
	}
	std::cout << "Unknown" << std::endl;
}