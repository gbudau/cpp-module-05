#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

void	test_shrubbery_form(std::string const & target) {
	try {
		std::cout << "\n##### Testing ShrubberyCreationForm on " <<
			target + std::string("_shrubbery") << " #####\n";
		ShrubberyCreationForm	shrubbery_form(target);

		std::cout << shrubbery_form;
	}
	catch (const std::exception & exception) {
		std::cout << "##### An exception occurred #####\n" <<
			exception.what();
	}
}

void	test_robotomy_form(std::string const & target) {
	try {
		std::cout << "\n##### Testing RobotomyRequestForm on " <<
			target << " #####\n";
		RobotomyRequestForm	robotomy_form(target);

		std::cout << robotomy_form;
	}
	catch (const std::exception & exception) {
		std::cout << "##### An exception occurred #####\n" <<
			exception.what();
	}
}

void	test_presidential_form(std::string const & target) {
	try {
		std::cout << "\n##### Testing PresidentialPardonForm on " <<
			target << " #####\n";
		PresidentialPardonForm	presidential_form(target);

		std::cout << presidential_form;
	}
	catch (const std::exception & exception) {
		std::cout << "##### An exception occurred #####\n" <<
			exception.what();
	}
}

void	test_bureaucrat_and_shrubbery_form(std::string const & bureaucrat_name,
								int bureaucrat_grade,
								std::string const & target) {
	try {
		std::cout << "\n##### Testing bureaucrat " << bureaucrat_name <<
			" with ShrubberyCreationForm on " <<
			target + std::string("_shrubbery") << " #####\n";
		Bureaucrat	signer("Dave", 1);
		Bureaucrat	executor(bureaucrat_name, bureaucrat_grade);
		ShrubberyCreationForm	shrubbery_form(target);

		std::cout << signer << executor << shrubbery_form;
		signer.signForm(shrubbery_form);
		std::cout << shrubbery_form;
		shrubbery_form.beSigned(signer);
		shrubbery_form.execute(executor);
		executor.executeForm(shrubbery_form);
	}
	catch (const std::exception & exception) {
		std::cout << "##### An exception occurred #####\n" <<
			exception.what();
	}
}

void	test_bureaucrat_and_robotomy_form(std::string const & bureaucrat_name,
								int bureaucrat_grade,
								std::string const & target) {
	try {
		std::cout << "\n##### Testing bureaucrat " << bureaucrat_name <<
			" with RobotomyRequestForm on " << target << " #####\n";
		Bureaucrat	signer("Dave", 1);
		Bureaucrat	executor(bureaucrat_name, bureaucrat_grade);
		RobotomyRequestForm	robotomy_form(target);

		std::cout << signer << executor << robotomy_form;
		signer.signForm(robotomy_form);
		std::cout << robotomy_form;
		robotomy_form.beSigned(signer);
		robotomy_form.execute(executor);
		executor.executeForm(robotomy_form);
	}
	catch (const std::exception & exception) {
		std::cout << "##### An exception occurred #####\n" <<
			exception.what();
	}
}

void	test_bureaucrat_and_presidential_form(std::string const & bureaucrat_name,
								int bureaucrat_grade,
								std::string const & target) {
	try {
		std::cout << "\n##### Testing bureaucrat " << bureaucrat_name <<
			" with PresidentialPardonForm on " << target << " #####\n";
		Bureaucrat	signer("Dave", 1);
		Bureaucrat	executor(bureaucrat_name, bureaucrat_grade);
		PresidentialPardonForm	presidential_form(target);

		std::cout << signer << executor << presidential_form;
		signer.signForm(presidential_form);
		std::cout << presidential_form;
		presidential_form.beSigned(signer);
		presidential_form.execute(executor);
		executor.executeForm(presidential_form);
	}
	catch (const std::exception & exception) {
		std::cout << "##### An exception occurred #####\n" <<
			exception.what();
	}
}

int	main() {
	test_bureaucrat("Bob", 75);
	test_bureaucrat("Alice", 151);
	test_bureaucrat("Jim", 0);
	test_bureaucrat("Megan", 1);
	test_bureaucrat("Jim", 150);

	test_shrubbery_form("tree");
	test_shrubbery_form("home");

	test_robotomy_form("shark");
	test_robotomy_form("duck");

	test_presidential_form("Ford");
	test_presidential_form("Trillian");

	test_bureaucrat_and_shrubbery_form("Alice", 150, "tree");
	test_bureaucrat_and_shrubbery_form("Jim", 1, "home");

	test_bureaucrat_and_robotomy_form("Alice", 150, "shark");
	test_bureaucrat_and_robotomy_form("Jim", 1, "duck");

	test_bureaucrat_and_presidential_form("Alice", 150, "Ford");
	test_bureaucrat_and_presidential_form("Jim", 1, "Trillian");
}
