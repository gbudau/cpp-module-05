#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
	: Form("Robotomy Request Form", 72, 45, target) {
	static bool	seeded = false;

	if (!seeded) {
		srand(time(NULL));
		seeded = true;
	}
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
	: Form(src.getName(),
			src.getSignGrade(),
			src.getExecuteGrade(),
			src.getTarget()) {
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
		std::cout << getTarget() << " has been robotomized successfully\n";
	} else {
		std::cout << getTarget() << " robotomization attempt was a failure\n";
	}
}
