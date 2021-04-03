#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_
#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>
#include "Form.hpp"

// Forward declaration of Form class
// Fixes recursive inclusion error
class Form;

class Bureaucrat {
 public:
					Bureaucrat();
					Bureaucrat(std::string const & name, int grade);
					Bureaucrat(Bureaucrat const & src);
	virtual			~Bureaucrat();
	Bureaucrat &	operator=(Bureaucrat const & rhs);
	std::string		getName() const;
	int				getGrade() const;
	void			incrementGrade();
	void			decrementGrade();
	void			signForm(Form* form) const;
	class			GradeTooHighException;
	class			GradeTooLowException;


 private:
	const std::string	_name;
	int					_grade;
	static const int	_max_grade;
	static const int	_min_grade;
};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & rhs);

class Bureaucrat::GradeTooHighException : virtual public std::logic_error {
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

class Bureaucrat::GradeTooLowException : virtual public std::logic_error {
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

#endif  // BUREAUCRAT_HPP_
