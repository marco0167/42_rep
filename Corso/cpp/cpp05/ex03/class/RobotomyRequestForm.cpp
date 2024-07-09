#include "./RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("unknown") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy creation", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs)
{
	*this = rhs;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() && executor.getGrade() <= this->getGradeToExecute())
	{
		std::cout << "*Drill noises*" << std::endl;

		std::srand(std::time(0));
		short value = std::rand() % 2; // return 0 or 1

		if (value)
			std::cout << this->_target << " has been robotomized" << std::endl;
		else
			std::cout << this->_target << " robotomy failed" << std::endl;
	}
	else {
		std::cout << "Cannot not execute robotomy because: ";
		throw this->gradeTooLow;
	}
}
