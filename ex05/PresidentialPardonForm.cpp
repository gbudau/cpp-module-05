#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
	: Form("Presidential Pardon Form", 25, 5, target) {
}

PresidentialPardonForm::PresidentialPardonForm(
		PresidentialPardonForm const & src)
	: Form(src.getName(),
			src.getSignGrade(),
			src.getExecuteGrade(),
			src.getTarget()) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	canBeExecuted(executor);
	executeAction();
}

void	PresidentialPardonForm::executeAction() const {
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox\n";
}
