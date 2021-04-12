#ifndef CENTRALBUREAUCRACY_HPP_
#define CENTRALBUREAUCRACY_HPP_
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Form.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "OfficeBlock.hpp"

class CentralBureaucracy {
 public:
	CentralBureaucracy();
	virtual ~CentralBureaucracy();
	void	queueUp(std::string const & name);
	void	feedBureaucrat(Bureaucrat const & bureaucrat);
	void	doBureaucracy();

 private:
	CentralBureaucracy(CentralBureaucracy const & src);
	CentralBureaucracy &	operator=(CentralBureaucracy const & rhs);
	static const int		_max_size = 20;
	Intern					_intern;
	OfficeBlock				_office_blocks[_max_size];
	int						_current_size;
	struct					TargetList;
	TargetList*				_targets;
	TargetList*				_last_target;
};

struct CentralBureaucracy::TargetList {
	std::string	name;
	TargetList*	next;
};

#endif  // CENTRALBUREAUCRACY_HPP_
