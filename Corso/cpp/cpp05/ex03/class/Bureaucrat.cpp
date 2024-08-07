#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, short grade) : _name(name)
{
	if (grade >= 1 && grade <= 150)
		this->_grade = grade;
	else if (grade < 1)
		throw this->gradeTooHigh;
	else if (grade > 150)
		throw this->gradeTooLow;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs) : _name(rhs._name)
{
	*this = rhs;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs._grade;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &rhs)
{
	std::string str;

	str.append(rhs.getName());
	str.append(", bureaucrat grade ");
	str.append(std::to_string(rhs.getGrade()));
	str.append("\n");
	o << str;
	return o;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

short Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade > 1)
		this->_grade = ++_grade;
	else
		throw this->gradeTooHigh;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade < 150)
		this->_grade = --_grade;
	else
		throw this->gradeTooLow;
}

void	Bureaucrat::signForm(AForm& form) {
	if (form.getSigned())
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	else {
		std::cout << this->getName() << " couldn’t sign " << form.getName() << " because ";
		throw gradeTooLow;
	}
}

void	Bureaucrat::executeForm(AForm const & form) {

	form.execute(*this);

	std::cout << this->getName() << " executed " << form.getName() << std::endl;

}
