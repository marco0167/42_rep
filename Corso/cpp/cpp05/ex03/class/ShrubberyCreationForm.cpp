#include "./ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery creation", 145, 137), _target("unknown") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery creation", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs)
{
	*this = rhs;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string filename;

	if (this->getSigned() && executor.getGrade() <= this->getGradeToExecute())
	{
		filename = this->_target + "_shrubbery";
		std::ofstream outfile(filename);
		outfile << "       _-_" << std::endl;
		outfile << "    /~~   ~~\\" << std::endl;
		outfile << " /~~         ~~\\" << std::endl;
		outfile << "{               }" << std::endl;
		outfile << " \\  _-     -_  /" << std::endl;
		outfile << "   ~  \\\\ //  ~" << std::endl;
		outfile << "_- -   | | _- _" << std::endl;
		outfile << "  _ -  | |   -_" << std::endl;
		outfile << "      // \\\\" << std::endl;
		outfile.close();
	}
	else {
		std::cout << "Cannot not execute create file because: ";
		throw this->gradeTooLow;
	}
}
