#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock()
	: _intern(0),
	_signing_bureaucrat(0),
	_executing_bureaucrat(0) {
}

OfficeBlock::OfficeBlock(Intern const & intern,
	Bureaucrat const & signing_bureaucrat,
	Bureaucrat const & executing_bureaucrat)
	: _intern(&intern),
	_signing_bureaucrat(&signing_bureaucrat),
	_executing_bureaucrat(&executing_bureaucrat) {
}

void	OfficeBlock::doBureaucracy(std::string const & form_name,
											std::string const & target_name) {
	if (_intern && _signing_bureaucrat && _executing_bureaucrat) {
		Form*	new_form = _intern->makeForm(form_name, target_name);
		if (new_form) {
			_signing_bureaucrat->signForm(*new_form);
			_executing_bureaucrat->executeForm(*new_form);
			delete new_form;
		} else {
			throw FormNotFoundException("Form not found\n");
		}
	} else {
		throw BureaucracyCantBeDoneException("No bureaucracy can be done\n");
	}
}

void		OfficeBlock::setIntern(Intern const & intern) {
	_intern = &intern;
}

void		OfficeBlock::setSigner(Bureaucrat const & signing_bureaucrat) {
	_signing_bureaucrat = &signing_bureaucrat;
}

void		OfficeBlock::setExecutor(Bureaucrat const & executing_bureaucrat) {
	_executing_bureaucrat = &executing_bureaucrat;
}

OfficeBlock::~OfficeBlock() {
}

OfficeBlock::FormNotFoundException::FormNotFoundException(std::string what_arg)
	: std::logic_error(what_arg), _what_arg(what_arg) {
}

OfficeBlock::FormNotFoundException::FormNotFoundException(
	FormNotFoundException const & src)
	: std::logic_error(src._what_arg) {
	*this = src;
}

OfficeBlock::FormNotFoundException & OfficeBlock::FormNotFoundException::
								operator=(FormNotFoundException const & rhs) {
	if (this != &rhs) {
		_what_arg = rhs._what_arg;
	}
	return *this;
}

OfficeBlock::FormNotFoundException::~FormNotFoundException() {
}

OfficeBlock::BureaucracyCantBeDoneException::
	BureaucracyCantBeDoneException(std::string what_arg)
	: std::logic_error(what_arg), _what_arg(what_arg) {
}

OfficeBlock::BureaucracyCantBeDoneException::
	BureaucracyCantBeDoneException(BureaucracyCantBeDoneException const & src)
	: std::logic_error(src._what_arg) {
	*this = src;
}

OfficeBlock::BureaucracyCantBeDoneException & OfficeBlock::
	BureaucracyCantBeDoneException::operator=(
								BureaucracyCantBeDoneException const & rhs) {
	if (this != &rhs) {
		_what_arg = rhs._what_arg;
	}
	return *this;
}

OfficeBlock::BureaucracyCantBeDoneException::~BureaucracyCantBeDoneException() {
}
