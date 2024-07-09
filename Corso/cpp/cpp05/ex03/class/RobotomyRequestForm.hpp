#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib> // for rand()
# include <ctime>

class RobotomyRequestForm : public AForm {
	std::string	_target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &rhs);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

	void	execute(Bureaucrat const &executor) const;
};

#endif
