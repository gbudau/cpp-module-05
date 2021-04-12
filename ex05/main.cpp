#include <iostream>
#include <exception>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "CentralBureaucracy.hpp"

int	main() {
	CentralBureaucracy	cb;
	Bureaucrat*			bureaucrats[22];

	std::cout << "##### Testing Central Bureaucracy #####\n";
	try {
		std::srand(std::time(nullptr));
		int arrsize = sizeof(bureaucrats) / sizeof(bureaucrats[0]);
		for (int i = 0; i < arrsize; i++) {
			std::stringstream ss;
			ss << i;
			int	rand_grade = 1 + std::rand() % 150;
			bureaucrats[i] = new Bureaucrat(
								std::string("bureaucrat") + ss.str(), rand_grade);
			cb.feedBureaucrat(*bureaucrats[i]);
		}
		for (int i = 0; i < 10; i++) {
			std::stringstream ss;
			ss << i;
			cb.queueUp("target" + ss.str());
		}
		cb.doBureaucracy();
		for (int i = 0; i < arrsize; i++) {
			delete bureaucrats[i];
		}
	}
	catch (const std::exception & exception) {
		std::cout << "##### An exception occurred #####\n" <<
		exception.what();
	}
}
