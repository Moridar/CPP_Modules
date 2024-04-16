#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	std::cout << "==1. Pointer constructors==" << std::endl;
	Base *Ap= new A();
	Base *Bp = new B();
	Base *Cp = new C();
	Base *Random = Base::generate();
	Base *base = new Base();

	std::cout << std::endl << "==3. Identify by pointer==" << std::endl;
	Base::identify(Ap);
	Base::identify(Bp);
	Base::identify(Cp);
	Base::identify(Random);
	Base::identify(NULL); 
	Base::identify(base);
	
	std::cout << std::endl << "==4. Identify by reference==" << std::endl;
	Base::identify(*Ap);
	Base::identify(*Bp);
	Base::identify(*Cp);
	Base::identify(*Random);
	Base::identify(NULL); 
	Base::identify(*base);
	
	std::cout << std::endl << "==5. Delete pointers==" << std::endl;
	delete Ap;
	delete Bp;
	delete Cp;
	delete Random;
	delete base;
	return (0);
}