#include "../class/Span.hpp"
#include <iostream>

int main()
{

		Span sp = Span(5);
	try
	{
		sp.addRandomNumbers(6);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//? if u want to use the code below u need to make the _container attribute PUBLIC
	// for(int i = 0; i< sp._container.size(); i++) {
	// 	std::cout << sp._container[i] << std::endl;
	// }
}
