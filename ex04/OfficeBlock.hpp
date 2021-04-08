#ifndef OFFICEBLOCK_HPP_
#define OFFICEBLOCK_HPP_
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

class OfficeBlock {
 public:
	OfficeBlock();
	OfficeBlock(Intern* intern, Bureaucrat* signing_bureaucrat,
											Bureaucrat* executing_bureaucrat);
	virtual ~OfficeBlock();
	void	doBureaucracy(std::string const & form_name,
											std::string const & target_name);
	Intern*		getIntern() const;
	Bureaucrat*	getSigningBureaucrat() const;
	Bureaucrat*	getExecutingBureaucrat() const;
	void		setIntern(Intern* intern);
	void		setSigningBureaucrat(Bureaucrat* signing_bureaucrat);
	void		setExecutingBureaucrat(Bureaucrat* executing_bureaucrat);
	class		FormNotFoundException;
	class		BureaucracyCantBeDoneException;

 private:
	OfficeBlock(OfficeBlock const & src);
	OfficeBlock &	operator=(OfficeBlock const & rhs);
	Intern*			_intern;
	Bureaucrat*		_signing_bureaucrat;
	Bureaucrat*		_executing_bureaucrat;
};

class OfficeBlock::FormNotFoundException : virtual public std::logic_error {
 public:
							FormNotFoundException();
							FormNotFoundException(std::string what_arg);
							FormNotFoundException(
									FormNotFoundException const & src);
	virtual					~FormNotFoundException();
	FormNotFoundException &	operator=(FormNotFoundException const & rhs);

 private:
	std::string	_what_arg;
};

class OfficeBlock::BureaucracyCantBeDoneException
											: virtual public std::logic_error {
 public:
							BureaucracyCantBeDoneException();
							BureaucracyCantBeDoneException(
														std::string what_arg);
							BureaucracyCantBeDoneException(
									BureaucracyCantBeDoneException const & src);
	virtual					~BureaucracyCantBeDoneException();
	BureaucracyCantBeDoneException &	operator=(
									BureaucracyCantBeDoneException const & rhs);

 private:
	std::string	_what_arg;
};

#endif  // OFFICEBLOCK_HPP_
