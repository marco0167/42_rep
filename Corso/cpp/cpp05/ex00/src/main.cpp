#include "../class/Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat buro("ddd", 10);
		buro.decrementGrade();
		std::cout << buro;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
