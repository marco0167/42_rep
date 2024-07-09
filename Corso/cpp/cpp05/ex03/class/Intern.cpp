#include "./Intern.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &rhs)
{
	*this = rhs;
}

Intern &Intern::operator=(const Intern &rhs)
{
	return *this;
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	std::map<std::string, AForm *> forms;

	forms["presidential pardon"] = new PresidentialPardonForm(target);
	forms["robotomy request"] = new RobotomyRequestForm(target);
	forms["shruberry creation"] = new ShrubberyCreationForm(target);
	
	AForm *form = forms[formName];

	if (form)
		std::cout << "Intern creates " << "\"" << formName << "\"" << std::endl;
	else
		std::cout << "\"" << formName << "\"" << " form doesen't exist!" << std::endl;
	return form;
}
