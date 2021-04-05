#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
	: Form("ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
	: Form(src.getName(), src.getSignGrade(), src.getExecuteGrade()),
	_target(src._target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	canBeExecuted(executor);
	executeAction();
}

void	ShrubberyCreationForm::executeAction() const {
	const std::string filename(_target + std::string("_shrubbery"));
	std::ofstream outf(filename);

	if (outf) {
		outf  << _ascii_tree;
	} else {
		std::cout << filename << " could not be opened for writing!\n";
	}
}

const std::string	ShrubberyCreationForm::_ascii_tree =
"                                                                \n"
"                                                                \n"
"                                                                \n"
"                                                                \n"
"                   ----         -====-                          \n"
"        --==--   -@@@@=-         ==@@@@-    -=====-             \n"
"       --===@@@=-@@======-         -==@@= -@@@@@@@@@=-          \n"
"           -===@@@@@@=@=====    --=====@@=@====-=---  -         \n"
"       -=@@@@@-=@====@@@=-   -@@@@@@@=@@@@@==-=@@@@@=-          \n"
"      @@@@@-  -@@@-==---@@= -@@@@==  -@-@@-=@@-  =@@@@@-        \n"
"     === -    -@@@- -@- --= =@@- -  -@  @@@ =@@@-  --=-@=       \n"
"              -@@@-   @=     @--   -@- -@@@- =@@@-      @-      \n"
"               @@@-    =@    -    -@-  -=@@- ==@@=       -      \n"
"               -==-     =@        @=   -@@=   -@@               \n"
"                         @=      -@    -@-    ==                \n"
"                         -@-     @=                             \n"
"                          @@    -@                              \n"
"                          =@    @=                              \n"
"                          =@-  =@                               \n"
"                          -@= -@-                               \n"
"                          -@@-@@                                \n"
"                        --=====--                               \n"
"                                                                \n"
"                                                                \n"
"                                                                \n"
"                                                                \n";
