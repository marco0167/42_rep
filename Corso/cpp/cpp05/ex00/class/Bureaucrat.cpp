#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, short grade) : _name(name)
{
	if (_grade >= 1 && _grade <= 150)
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
