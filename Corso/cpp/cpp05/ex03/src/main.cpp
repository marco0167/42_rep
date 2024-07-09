#include "../class/Bureaucrat.hpp"
#include "../class/Intern.hpp"

int main()
{
	try
	{
		Bureaucrat buro("ddd", 2);
		Intern intern;
		intern.makeForm("presidential kpardon", "target");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
