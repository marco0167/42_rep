#include "./Form.hpp"

Form::Form() : name("Default"), isSigned(false), gradeToExecute(150), gradeToSign(150) {}

Form::Form(std::string name, short gradeToSign, short gradeToExecute) : name(name), isSigned(false), gradeToExecute(gradeToExecute), gradeToSign(gradeToSign)
{
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw this->gradeTooHigh;
	else if (gradeToExecute > 150 || gradeToSign > 150)
		throw this->gradeTooLow;
}

Form::~Form() {}

Form::Form(const Form &rhs) : name(rhs.name), gradeToExecute(rhs.gradeToExecute), gradeToSign(rhs.gradeToSign)
{
	*this = rhs;
}

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
	{
		this->isSigned = rhs.isSigned;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Form &rhs)
{
	std::string str;

	str.append(rhs.getName());
	str.append(", burocrat is signed to form: ");
	if (rhs.getSigned())
		str.append("true");
	else
		str.append("false");
	str.append(", form grade to sign in: ");
	str.append(std::to_string(rhs.getGradeToSign()));
	str.append(", form grade to execute: ");
	str.append(std::to_string(rhs.getGradeToExecute()));
	str.append("\n");
	o << str;
	return o;
}

void Form::beSigned(Bureaucrat& rhs)
{
	if (rhs.getGrade() <= this->getGradeToSign())
		this->isSigned = true;
	rhs.signForm(*this);
}

std::string	Form::getName() {
	return this->name;
}

bool	Form::getSigned() {
	return this->isSigned;
}

short	Form::getGradeToSign() {
	return this->gradeToSign;
}

short	Form::getGradeToExecute() {
	return this->gradeToExecute;
}

