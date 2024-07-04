#include "../class/Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat buro("ddd", 10);
		Form form("Form1", 15, 15);
		buro.decrementGrade();
		std::cout << form;
		form.beSigned(buro);
		std::cout << form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
