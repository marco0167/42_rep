#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
#include <map>

class Intern {

public:
	Intern();
	~Intern();
	Intern(const Intern &rhs);
	Intern &operator=(const Intern &rhs);

	AForm*	makeForm(std::string formName, std::string target);
};

#endif
