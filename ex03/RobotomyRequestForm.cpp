#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
	: Form("RobotomyRequestForm", 72, 45), _target(target) {
	static bool	seeded = false;

	if (!seeded) {
		srand(time(NULL));
		seeded = true;
	}
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
	: Form(src.getName(), src.getSignGrade(), src.getExecuteGrade()),
	_target(src._target) {
	static bool	seeded = false;

	if (!seeded) {
		srand(time(NULL));
		seeded = true;
	}
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	canBeExecuted(executor);
	executeAction();
}

void	RobotomyRequestForm::executeAction() const {
	std::cout << "* Trrrrr Rrrrrr Trrrrr *\n";
	if (rand() % 2) {
		std::cout << _target << " has been robotomized successfully\n";
	} else {
		std::cout << _target << " robotomization attempt was a failure\n";
	}
}
