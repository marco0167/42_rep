#include "./PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential creation", 25, 5), _target("unknown") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential creation", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs)
{
	*this = rhs;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() && executor.getGrade() <= this->getGradeToExecute())
	{
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	else {
		std::cout << "Cannot be pardoned because: ";
		throw this->gradeTooLow;
	}
}
