#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat {
	const	std::string	_name;
	short				_grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, short grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &rhs);
	Bureaucrat &operator=(const Bureaucrat &rhs);

	std::string	getName();
	short		getGrade();

	void		incrementGrade();
	void		decrementGrade();

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

std::ostream & operator<<( std::ostream & o, Bureaucrat& rhs);

#endif
