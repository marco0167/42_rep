#include "../class/Base.hpp"

int main() {
	Base* a = generate();
	identify(a);
	identify(*a);
	std::cout << std::endl;

	Base* b = generate();
	identify(b);
	identify(*b);
	std::cout << std::endl;

	Base* c = generate();
	identify(c);
	identify(*c);
	std::cout << std::endl;

	Base* d = generate();
	identify(d);
	identify(*d);
	std::cout << std::endl;

	Base* e = generate();
	identify(e);
	identify(*e);
	std::cout << std::endl;

	Base* f = generate();
	identify(f);
	identify(*f);
	std::cout << std::endl;
}
