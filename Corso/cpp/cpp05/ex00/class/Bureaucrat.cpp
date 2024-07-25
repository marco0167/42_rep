#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, short grade) : _name(name)
{
	if (grade >= 1 && grade <= 150)
		this->_grade = grade;
	else if (grade < 1)
		throw this->gradeTooHigh;
	else
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
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return o;
}

std::string Bureaucrat::getName()
{
	return this->_name;
}

short Bureaucrat::getGrade()
{
	return this->_grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade > 1)
		this->_grade = ++_grade;
	else
		throw this->gradeTooHigh;
}

void Bureaucrat::decrementGrade()
{
	if (_grade < 150)
		this->_grade = --_grade;
	else
		throw this->gradeTooLow;
}
