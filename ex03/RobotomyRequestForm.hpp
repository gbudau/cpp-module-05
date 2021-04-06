#ifndef ROBOTOMYREQUESTFORM_HPP_
#define ROBOTOMYREQUESTFORM_HPP_
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form {
 public:
			RobotomyRequestForm(std::string const & target);
			RobotomyRequestForm(RobotomyRequestForm const & src);
	virtual	~RobotomyRequestForm();
	void	execute(Bureaucrat const & executor) const;

 protected:
	void	executeAction() const;

 private:
	RobotomyRequestForm();
	RobotomyRequestForm &	operator=(RobotomyRequestForm const & rhs);
	std::string					_target;
};

#endif  // ROBOTOMYREQUESTFORM_HPP_
