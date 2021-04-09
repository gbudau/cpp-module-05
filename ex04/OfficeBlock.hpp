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
	OfficeBlock(Intern const & intern, Bureaucrat const & signing_bureaucrat,
										Bureaucrat const & executing_bureaucrat);
	virtual ~OfficeBlock();
	void	doBureaucracy(std::string const & form_name,
										std::string const & target_name) const;
	void		setIntern(Intern const & intern);
	void		setSigner(Bureaucrat const & signing_bureaucrat);
	void		setExecutor(Bureaucrat const & executing_bureaucrat);
	class		FormNotFoundException;
	class		BureaucracyCantBeDoneException;

 private:
	OfficeBlock(OfficeBlock const & src);
	OfficeBlock &	operator=(OfficeBlock const & rhs);
	const Intern*			_intern;
	const Bureaucrat*		_signing_bureaucrat;
	const Bureaucrat*		_executing_bureaucrat;
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
