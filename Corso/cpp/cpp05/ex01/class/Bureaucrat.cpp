#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, short grade) : name(name)
{
	if (grade >= 1 && grade <= 150)
		this->grade = grade;
	else if (grade < 1)
		throw this->gradeTooHigh;
	else if (grade > 150)
		throw this->gradeTooLow;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs) : name(rhs.name)
{
	*this = rhs;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		this->grade = rhs.grade;
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
	return this->name;
}

short Bureaucrat::getGrade()
{
	return this->grade;
}

void Bureaucrat::incrementGrade()
{
	if (grade > 1)
		this->grade = ++grade;
	else
		throw this->gradeTooHigh;
}

void Bureaucrat::decrementGrade()
{
	if (grade < 150)
		this->grade = --grade;
	else
		throw this->gradeTooLow;
}

void	Bureaucrat::signForm(Form& form) {
	if (form.getSigned())
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	else {
		std::cout << this->getName() << " couldn’t sign " << form.getName() << " because ";
		throw gradeTooLow;
	}
}
