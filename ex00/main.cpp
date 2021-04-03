#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

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
		std::cerr << "##### An error occurred #####\n" <<
			exception.what();
	}
}

int	main() {
	test_bureaucrat("Bob", 75);
	test_bureaucrat("Jim", 151);
	test_bureaucrat("Jim", 0);
	test_bureaucrat("Bob", 1);
	test_bureaucrat("Jim", 150);
}
