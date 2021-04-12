#include "Intern.hpp"

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
	const _createFormType	createFormTypeList[] = {
		{"shrubbery creation", &Intern::_makeShrubberyCreationForm},
		{"robotomy request", &Intern::_makeRobotomyRequestForm},
		{"presidential pardon", &Intern::_makePresidentialPardonForm},
		{"mutant pig termination", &Intern::_makeMutantPigTerminationForm}};

	const int	forms_n = sizeof(createFormTypeList) / sizeof(_createFormType);

	for (int i = 0; i < forms_n; i++) {
		if (name == createFormTypeList[i].form_name) {
			Form*	new_form =
							(*this.*createFormTypeList[i].function_ptr)(target);
			std::cout << "Intern creates a " << new_form->getName() << 
				" (s.grade " << new_form->getSignGrade() << ", ex.grade " <<
				new_form->getExecuteGrade() << ") targeted on " <<
				new_form->getTarget() << " (" <<
				(new_form->getIsSigned() ? "Signed" : "Unsigned") << ")\n";
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

Form*		Intern::_makeMutantPigTerminationForm(
											std::string const & target) const {
	return new MutantPigTermination(target);
}
