#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm {
	std::string	_target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

	void execute(Bureaucrat const & executor) const;
};

#endif
