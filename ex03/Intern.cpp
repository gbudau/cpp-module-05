#include "Intern.hpp"

const int	Intern::_forms_n = 3;

Intern::Intern() {
}

Intern::Intern(Intern const & src) {
	*this = src;
}

Intern::~Intern() {
}

Intern &	Intern::operator=(Intern const & rhs) {
	if (this != &rhs) {;}
	return *this;
}

Form*		Intern::makeForm(std::string const & name,
											std::string const & target) const {
	std::string const	form_names[_forms_n] =
			{"shrubbery creation",
				"robotomy request",
				"presidential pardon"};
	Form*	(Intern::*const function_ptr[_forms_n])(std::string const &) const =
	{&Intern::_makeShrubberyCreationForm,
		&Intern::_makeRobotomyRequestForm,
		&Intern::_makePresidentialPardonForm};

	for (int i = 0; i < _forms_n; i++) {
		if (name == form_names[i]) {
			Form*	new_form = (*this.*function_ptr[i])(target);
			std::cout << "Intern creates " << new_form->getName() << "\n";
			return new_form;
		}
	}
	std:: cout << "Intern cannot find " << name << "\n";
	return 0;
}

Form*		Intern::_makeShrubberyCreationForm(
											std::string const & target) const {
	return new ShrubberyCreationForm(target);
}

Form*		Intern::_makeRobotomyRequestForm(std::string const & target) const {
	return new RobotomyRequestForm(target);
}

Form*		Intern::_makePresidentialPardonForm(
											std::string const & target) const {
	return new PresidentialPardonForm(target);
}
