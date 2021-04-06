#ifndef SHRUBBERYCREATIONFORM_HPP_
#define SHRUBBERYCREATIONFORM_HPP_
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form {
 public:
			ShrubberyCreationForm(std::string const & target);
			ShrubberyCreationForm(ShrubberyCreationForm const & src);
	virtual	~ShrubberyCreationForm();
	void	execute(Bureaucrat const & executor) const;

 protected:
	void	executeAction() const;

 private:
	ShrubberyCreationForm();
	ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & rhs);
	std::string					_target;
	static const std::string	_ascii_tree;
};

#endif  // SHRUBBERYCREATIONFORM_HPP_
