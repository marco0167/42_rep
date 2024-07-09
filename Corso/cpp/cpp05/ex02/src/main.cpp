#include "../class/Bureaucrat.hpp"
#include "../class/RobotomyRequestForm.hpp"
#include "../class/PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat buro("ddd", 26);
		PresidentialPardonForm form("form");
		form.beSigned(buro);
		// form.execute(buro);
		buro.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
