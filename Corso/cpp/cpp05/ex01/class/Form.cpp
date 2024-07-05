#include "./Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeToExecute(150), _gradeToSign(150) {}

Form::Form(std::string name, short gradeToSign, short gradeToExecute) : _name(name), _isSigned(false), _gradeToExecute(gradeToExecute), _gradeToSign(gradeToSign)
{
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw this->gradeTooHigh;
	else if (gradeToExecute > 150 || gradeToSign > 150)
		throw this->gradeTooLow;
}

Form::~Form() {}

Form::Form(const Form &rhs) : _name(rhs._name), _gradeToExecute(rhs._gradeToExecute), _gradeToSign(rhs._gradeToSign)
{
	*this = rhs;
}

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
	{
		this->_isSigned = rhs._isSigned;
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
		this->_isSigned = true;
	rhs.signForm(*this);
}

std::string	Form::getName() {
	return this->_name;
}

bool	Form::getSigned() {
	return this->_isSigned;
}

short	Form::getGradeToSign() {
	return this->_gradeToSign;
}

short	Form::getGradeToExecute() {
	return this->_gradeToExecute;
}

