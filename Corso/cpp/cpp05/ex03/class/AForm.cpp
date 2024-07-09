#include "./AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToExecute(150), _gradeToSign(150) {}

AForm::AForm(std::string name, short gradeToSign, short gradeToExecute) : _name(name), _isSigned(false), _gradeToExecute(gradeToExecute), _gradeToSign(gradeToSign)
{
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw this->gradeTooHigh;
	else if (gradeToExecute > 150 || gradeToSign > 150)
		throw this->gradeTooLow;
}

AForm::~AForm() {}

AForm::AForm(const AForm &rhs) : _name(rhs._name), _gradeToExecute(rhs._gradeToExecute), _gradeToSign(rhs._gradeToSign)
{
	*this = rhs;
}

AForm &AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
	{
		this->_isSigned = rhs._isSigned;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, AForm &rhs)
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

void AForm::beSigned(Bureaucrat& rhs)
{
	if (rhs.getGrade() <= this->getGradeToSign())
		this->_isSigned = true;
	rhs.signForm(*this);
}

std::string	AForm::getName() const {
	return this->_name;
}

bool	AForm::getSigned() const {
	return this->_isSigned;
}

short	AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

short	AForm::getGradeToExecute() const {
	return this->_gradeToExecute;
}

