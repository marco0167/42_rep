#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
class Bureaucrat;

class AForm {
	const std::string	_name;
	bool				_isSigned;
	const short			_gradeToSign;
	const short			_gradeToExecute;

public:
	AForm();
	AForm(std::string name, short gradeTosign, short gradeToExecute);
	~AForm();
	AForm(const AForm &rhs);
	AForm &operator=(const AForm &rhs);

	std::string	getName() const;
	bool		getSigned() const;
	short		getGradeToSign() const;
	short		getGradeToExecute() const;

	void		beSigned(Bureaucrat& rhs);

	virtual void execute(Bureaucrat const & executor) const = 0;

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

std::ostream & operator<<( std::ostream & o, AForm& rhs);


#endif
