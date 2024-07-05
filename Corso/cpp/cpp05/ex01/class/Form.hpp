#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
class Bureaucrat;

class Form {
	const std::string	_name;
	bool				_isSigned;
	const short			_gradeToSign;
	const short			_gradeToExecute;

public:
	Form();
	Form(std::string name, short gradeTosign, short gradeToExecute);
	~Form();
	Form(const Form &rhs);
	Form &operator=(const Form &rhs);

	std::string	getName();
	bool		getSigned();
	short		getGradeToSign();
	short		getGradeToExecute();

	void		beSigned(Bureaucrat& rhs);

	class GradeTooHighException: public std::exception {
		virtual const char* what() const throw() {
			return "Grade too High";
		}
	} gradeTooHigh;

	class GradeTooLowException: public std::exception {
		virtual const char* what() const throw() {
			return "Grade Too Low";
		}
	} gradeTooLow;
};

std::ostream & operator<<( std::ostream & o, Form& rhs);


#endif
