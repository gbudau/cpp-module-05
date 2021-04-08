#include "Bureaucrat.hpp"

const int	Bureaucrat::_max_grade = 1;
const int	Bureaucrat::_min_grade = 150;

Bureaucrat::Bureaucrat(std::string const & name, int grade)
	: _name(name), _grade(grade) {
	if (grade < _max_grade) {
		throw GradeTooHighException("Grade too high. The highest grade is 1\n");
	} else if (grade > _min_grade) {
		throw GradeTooLowException("Grade too low. The lowest grade is 150\n");
	}
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
	: _name(src._name), _grade(src._grade) {
}

std::string		Bureaucrat::getName() const {
	return _name;
}

int				Bureaucrat::getGrade() const {
	return _grade;
}

void			Bureaucrat::incrementGrade() {
	if (_grade - 1 < _max_grade) {
		throw GradeTooHighException(
				"Cannot increment the grade. The highest grade is 1.\n");
	} else {
		_grade--;
	}
}

void			Bureaucrat::decrementGrade() {
	if (_grade + 1 > _min_grade) {
		throw GradeTooHighException(
				"Cannot decrement the grade. The lowest grade is 150.\n");
	} else {
		_grade++;
	}
}

void			Bureaucrat::signForm(Form & form) const {
	try {
		form.beSigned(*this);
		std::cout << getName() << " signs form " << form.getName() << "\n";
	}
	catch (const std::exception & exception) {
		std::cout << getName() << " cannot sign form " << form.getName() <<
			" because it doesn't have the required grade\n";
	}
}

void			Bureaucrat::executeForm(Form const & form) const {
	try {
		form.execute(*this);
		std::cout << getName() << " executes " << form.getName() << "\n";
	}
	catch (const std::exception & exception) {
		std::cout << exception.what();
	}
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "\n";
	return o;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string what_arg)
	: std::logic_error(what_arg), _what_arg(what_arg) {
}

Bureaucrat::GradeTooHighException::GradeTooHighException(
		GradeTooHighException const & src) : std::logic_error(src._what_arg) {
	*this = src;
}

Bureaucrat::GradeTooHighException & Bureaucrat::GradeTooHighException::operator=
(GradeTooHighException const & rhs) {
	if (this != &rhs) {
		_what_arg = rhs._what_arg;
	}
	return *this;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() {
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string what_arg)
	: std::logic_error(what_arg), _what_arg(what_arg) {
}

Bureaucrat::GradeTooLowException::GradeTooLowException(
		GradeTooLowException const & src) : std::logic_error(src._what_arg) {
	*this = src;
}

Bureaucrat::GradeTooLowException & Bureaucrat::GradeTooLowException::operator=(
		GradeTooLowException const & rhs) {
	if (this != &rhs) {
		_what_arg = rhs._what_arg;
	}
	return *this;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() {
}
