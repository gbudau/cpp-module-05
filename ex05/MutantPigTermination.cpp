#include "MutantPigTermination.hpp"

MutantPigTermination::MutantPigTermination(std::string const & target)
	: Form("Mutant Pig Termination Form", 130, 50, target) {
}

MutantPigTermination::MutantPigTermination(
		MutantPigTermination const & src)
	: Form(src.getName(),
			src.getSignGrade(),
			src.getExecuteGrade(),
			src.getTarget()) {
}

MutantPigTermination::~MutantPigTermination() {
}

void	MutantPigTermination::execute(Bureaucrat const & executor) const {
	canBeExecuted(executor);
	executeAction();
}

void	MutantPigTermination::executeAction() const {
	std::cout << "That'll do, " << getTarget() << ". That'll do...\n";
}
