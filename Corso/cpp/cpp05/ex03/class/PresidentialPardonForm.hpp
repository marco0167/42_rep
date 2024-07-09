#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	std::string	_target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string  target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &rhs);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

	void	execute(Bureaucrat const &executor) const;
};

#endif
