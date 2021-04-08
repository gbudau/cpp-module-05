#ifndef PRESIDENTIALPARDONFORM_HPP_
#define PRESIDENTIALPARDONFORM_HPP_
#include <iostream>
#include <string>
#include <sstream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form {
 public:
			PresidentialPardonForm(std::string const & target);
			PresidentialPardonForm(PresidentialPardonForm const & src);
	virtual	~PresidentialPardonForm();
	void	execute(Bureaucrat const & executor) const;

 protected:
	void	executeAction() const;

 private:
	PresidentialPardonForm();
	PresidentialPardonForm &	operator=(PresidentialPardonForm const & rhs);
};

#endif  // PRESIDENTIALPARDONFORM_HPP_
