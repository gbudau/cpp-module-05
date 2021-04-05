#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
	: Form("PresidentialPardonForm", 25, 5), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(
		PresidentialPardonForm const & src)
	: Form(src.getName(), src.getSignGrade(), src.getExecuteGrade()),
	_target(src._target) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	canBeExecuted(executor);
	executeAction();
}

void	PresidentialPardonForm::executeAction() const {
	std::cout << _target << " has been pardoned by Zafod Beeblebrox\n";
}
