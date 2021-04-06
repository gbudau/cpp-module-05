#include "Form.hpp"

const int	Form::_max_grade = 1;
const int	Form::_min_grade = 150;

Form::Form(std::string const & name, int sign_grade, int execute_grade)
	: _name(name), _is_signed(false), _sign_grade(sign_grade),
	_execute_grade(execute_grade) {
	if (_sign_grade < _max_grade || _execute_grade < _max_grade) {
		throw GradeTooHighException("Grade too high. The highest grade is 1\n");
	} else if (_sign_grade > _min_grade || _execute_grade > _min_grade) {
		throw GradeTooLowException("Grade too low. The lowest grade is 150\n");
	}
}

Form::Form(Form const & src) : _name(src._name), _is_signed(src._is_signed),
	_sign_grade(src._sign_grade), _execute_grade(src._execute_grade) {
}

Form::~Form() {
}

std::string	Form::getName() const {
	return _name;
}

bool		Form::getIsSigned() const {
	return _is_signed;
}

int			Form::getSignGrade() const {
	return _sign_grade;
}

int			Form::getExecuteGrade() const {
	return _execute_grade;
}

void		Form::beSigned(Bureaucrat const & bureaucrat) {
	if (bureaucrat.getGrade() > _sign_grade) {
		std::ostringstream	buffer;

		buffer << "Form "<< _name << " requires grade " <<
			_sign_grade << " or higher to sign\n";
		throw Form::GradeTooLowException(buffer.str());
	}
	_is_signed = true;
}

void		Form::canBeExecuted(Bureaucrat const & executor) const {
	if (!getIsSigned()) {
		throw NotSignedException(getName() +
				" is not signed and cannot be executed\n");
	} else if (executor.getGrade() > getExecuteGrade()) {
		std::ostringstream	buffer;

		buffer << "Form "<< getName() << " requires grade " <<
			getExecuteGrade() << " or higher to execute\n";
		throw GradeTooLowException(buffer.str());
	}
}

std::ostream &	operator<<(std::ostream & out, Form const & rhs) {
	out << "Form " << rhs.getName() << ", grade required to sign " <<
		rhs.getSignGrade() << ", grade required to execute " <<
		rhs.getExecuteGrade() << ", is " <<
		(rhs.getIsSigned() ? "signed\n" : "not signed\n");
	return out;
}

Form::GradeTooHighException::GradeTooHighException(std::string what_arg)
	: std::logic_error(what_arg), _what_arg(what_arg) {
}

Form::GradeTooHighException::GradeTooHighException(
		GradeTooHighException const & src) : std::logic_error(src._what_arg) {
	*this = src;
}

Form::GradeTooHighException & Form::GradeTooHighException::operator=
(GradeTooHighException const & rhs) {
	if (this != &rhs) {
		_what_arg = rhs._what_arg;
	}
	return *this;
}

Form::GradeTooHighException::~GradeTooHighException() {
}

Form::GradeTooLowException::GradeTooLowException(std::string what_arg)
	: std::logic_error(what_arg), _what_arg(what_arg) {
}

Form::GradeTooLowException::GradeTooLowException(
		GradeTooLowException const & src) : std::logic_error(src._what_arg) {
	*this = src;
}

Form::GradeTooLowException & Form::GradeTooLowException::operator=(
		GradeTooLowException const & rhs) {
	if (this != &rhs) {
		_what_arg = rhs._what_arg;
	}
	return *this;
}

Form::GradeTooLowException::~GradeTooLowException() {
}

Form::NotSignedException::NotSignedException(std::string what_arg)
	: std::logic_error(what_arg), _what_arg(what_arg) {
}

Form::NotSignedException::NotSignedException(
		NotSignedException const & src)
	: std::logic_error(src._what_arg) {
	*this = src;
}

Form::NotSignedException & Form::NotSignedException::operator=(
		NotSignedException const & rhs) {
	if (this != &rhs) {
		_what_arg = rhs._what_arg;
	}
	return *this;
}

Form::NotSignedException::~NotSignedException() {
}
