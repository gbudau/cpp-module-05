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
	struct				_createFormType;
};

struct Intern::_createFormType {
	typedef Form* (Intern::*ptr2Member)(std::string const &) const;

	std::string const	form_name;
	ptr2Member	const	function_ptr;
};

#endif  // INTERN_HPP_
