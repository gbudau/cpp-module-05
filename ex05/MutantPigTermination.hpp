#ifndef MUTANTPIGTERMINATION_HPP_
#define MUTANTPIGTERMINATION_HPP_
#include <iostream>
#include <string>
#include <sstream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class MutantPigTermination : public Form {
 public:
			MutantPigTermination(std::string const & target);
			MutantPigTermination(MutantPigTermination const & src);
	virtual	~MutantPigTermination();
	void	execute(Bureaucrat const & executor) const;

 protected:
	void	executeAction() const;

 private:
	MutantPigTermination();
	MutantPigTermination &	operator=(MutantPigTermination const & rhs);
};

#endif  // MUTANTPIGTERMINATION_HPP_
