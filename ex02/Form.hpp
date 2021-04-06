#ifndef FORM_HPP_
#define FORM_HPP_
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include "Bureaucrat.hpp"

// Forward declaration of Bureaucrat class
// Fixes recursive inclusion error
class Bureaucrat;

class Form {
 public:
					Form(std::string const & name, int sign_grade,
						int execute_grade, std::string const & target);
					Form(Form const & src);
	virtual			~Form();
	std::string		getName() const;
	bool			getIsSigned() const;
	int				getSignGrade() const;
	int				getExecuteGrade() const;
	std::string		getTarget() const;
	void			beSigned(Bureaucrat const & bureaucrat);
	class			GradeTooHighException;
	class			GradeTooLowException;
	class			NotSignedException;
	virtual void	execute(Bureaucrat const & executor) const = 0;

 protected:
	void			canBeExecuted(Bureaucrat const & executor) const;
	virtual void	executeAction() const = 0;

 private:
						Form();
	Form &				operator=(Form const & rhs);
	const std::string	_name;
	bool				_is_signed;
	const int			_sign_grade;
	const int			_execute_grade;
	const std::string	_target;
	static const int	_max_grade;
	static const int	_min_grade;
};

std::ostream &	operator<<(std::ostream & out, Form const & rhs);

class Form::GradeTooHighException : virtual public std::logic_error {
 public:
							GradeTooHighException();
							GradeTooHighException(std::string what_arg);
							GradeTooHighException(
									GradeTooHighException const & src);
	virtual					~GradeTooHighException();
	GradeTooHighException &	operator=(GradeTooHighException const & rhs);

 private:
	std::string	_what_arg;
};

class Form::GradeTooLowException : virtual public std::logic_error {
 public:
							GradeTooLowException();
							GradeTooLowException(std::string what_arg);
							GradeTooLowException(
									GradeTooLowException const & src);
	virtual					~GradeTooLowException();
	GradeTooLowException &	operator=(GradeTooLowException const & rhs);

 private:
	std::string	_what_arg;
};

class Form::NotSignedException : virtual public std::logic_error {
 public:
							NotSignedException();
							NotSignedException(std::string what_arg);
							NotSignedException(NotSignedException const & src);
	virtual					~NotSignedException();
	NotSignedException &	operator=(
			NotSignedException const & rhs);

 private:
	std::string	_what_arg;
};

#endif  // FORM_HPP_
