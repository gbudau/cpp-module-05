#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void	test_bureaucrat(std::string const & name, int grade) {
	try {
		std::cout << "\n##### Testing bureaucrat " << name << " #####\n";
		Bureaucrat	bureaucrat(name, grade);

		std::cout << bureaucrat;

		std::cout << "### Testing increment grade ###\n";
		bureaucrat.incrementGrade();
		std::cout << bureaucrat;

		std::cout << "### Testing decrement grade ###\n";
		bureaucrat.decrementGrade();
		std::cout << bureaucrat;

		std::cout << "### Testing decrement grade ###\n";
		bureaucrat.decrementGrade();
		std::cout << bureaucrat;
	}
	catch (const std::exception & exception) {
		std::cout << "##### An exception occurred #####\n" <<
			exception.what();
	}
}

void	test_form(std::string const & name, int sign_grade, int execute_grade) {
	try {
		std::cout << "\n##### Testing form " << name << " #####\n";
		Form	form(name, sign_grade, execute_grade);

		std::cout << form;
	}
	catch (const std::exception & exception) {
		std::cout << "##### An exception occurred #####\n" <<
			exception.what();
	}
}

void	test_bureaucrat_and_form(std::string const & bureaucrat_name,
								int bureaucrat_grade,
								std::string const & form_name,
								int form_sign_grade, int form_execute_grade) {
	try {
		std::cout << "\n##### Testing bureaucrat " << bureaucrat_name <<
			" with form " << form_name << " #####\n";
		Bureaucrat bureaucrat(bureaucrat_name, bureaucrat_grade);
		Form form(form_name, form_sign_grade, form_execute_grade);

		std::cout << bureaucrat << form;
		bureaucrat.signForm(&form);
		std::cout << form;
		form.beSigned(bureaucrat);
	}
	catch (const std::exception & exception) {
		std::cout << "##### An exception occurred #####\n" <<
			exception.what();
	}
}

int	main() {
	test_bureaucrat("Bob", 75);
	test_bureaucrat("Jim", 151);
	test_bureaucrat("Jim", 0);
	test_bureaucrat("Bob", 1);
	test_bureaucrat("Jim", 150);

	test_form("0356H", 0, 75);
	test_form("0356H", 75, 0);
	test_form("0356H", 75, 151);
	test_form("0356H", 151, 75);
	test_form("0356H", 75, 75);
	test_form("0356H", 1, 150);

	test_bureaucrat_and_form("Bob", 150, "0356H", 75, 75);
	test_bureaucrat_and_form("Jim", 1, "0356H", 1, 150);
}
