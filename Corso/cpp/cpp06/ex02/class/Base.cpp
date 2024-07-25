#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *	generate(void) {
	short	randomNum = rand() % 3;

	switch (randomNum) {
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			std::cout << "Error occurred!" << std::endl;
			return NULL;
	}
}

void	identify(Base* p) {
	Base* castArray[3] = {
		dynamic_cast<A*> (p),
		dynamic_cast<B*> (p),
		dynamic_cast<C*> (p),
	};
	std::string	typeArray[3] = {"A", "B", "C"};

	for (short i = 0; i < 3; i++)
	{
		if (castArray[i] != NULL)
		{
			std::cout << "Type " << typeArray[i] << std::endl;
			return;
		}
	}
	std::cout << "Can't identify any type!" << std::endl;
}

void	identify(Base& p) {
	try {
		dynamic_cast<A&> (p);
		std::cout << "Type A" << std::endl;
	} catch(...) {}

	try  {
		dynamic_cast<B&> (p);
		std::cout << "Type B" << std::endl;
	} catch(...) {}

	try{
		dynamic_cast<C&> (p);
		std::cout << "Type C" << std::endl;
	} catch(...) {}
}
