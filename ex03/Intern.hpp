#ifndef INTERN_HPP_
#define INTERN_HPP_
#include <iostream>
#include <string>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
 public:
				Intern();
				Intern(Intern const & src);
	virtual		~Intern();
	Intern &	operator=(Intern const & rhs);
	Form*		makeForm(std::string const & name,
											std::string const & target) const;

 private:
	Form*				_makeShrubberyCreationForm(
											std::string const & target) const;
	Form*				_makeRobotomyRequestForm(
											std::string const & target) const;
	Form*				_makePresidentialPardonForm(
											std::string const & target) const;
	static const int	_forms_n;
};

#endif  // INTERN_HPP_
