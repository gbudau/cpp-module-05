#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy()
	: _intern(), _office_blocks(), _current_size(0),
	_targets(0), _last_target(0) {
	static bool	seeded = false;

	if (!seeded) {
		std::srand(time(NULL));
		seeded = true;
	}
}

CentralBureaucracy::~CentralBureaucracy() {
	TargetList* tmp;

	while (_targets) {
		tmp = _targets->next;
		delete _targets;
		_targets = tmp;
	}
}

void	CentralBureaucracy::queueUp(std::string const & name) {
	TargetList*	new_target = new TargetList;

	new_target->name = name;
	new_target->next = 0;
	if (!_targets) {
		_targets = new_target;
		_last_target = _targets;
	} else {
		_last_target->next = new_target;
		_last_target = new_target;
	}
}

void	CentralBureaucracy::feedBureaucrat(Bureaucrat const & bureaucrat) {
	if (_current_size != _max_size) {
		_office_blocks[_current_size].setIntern(_intern);
		_office_blocks[_current_size].setSigner(bureaucrat);
		_office_blocks[_current_size].setExecutor(bureaucrat);
		_current_size++;
	} else {
		std::cout << "Central Bureaucracy reached its maximum capacity.\n";
	}
}

void	CentralBureaucracy::doBureaucracy() {
	const std::string form_names[] = {"shrubbery creation", "robotomy request",
							"presidential pardon", "mutant pig termination"};
	if (!_targets) {
		std::cout << "Central Bureaucracy cannot do bureaucracy. "
			"There are no targets in queue\n";
	}
	int	current_office = 0;
	while (_targets) {
		TargetList*	next_target = _targets->next;

		int	arrsize = sizeof(form_names) / sizeof(form_names[0]);
		int	rand_idx = std::rand() % arrsize;
		try {
			_office_blocks[current_office].doBureaucracy(
										form_names[rand_idx], _targets->name);
		}
		catch (const std::exception & exception) {
				exception.what();
		}
		delete _targets;
		_targets = next_target;
		current_office = (current_office + 1) % _current_size;
	}
	_last_target = 0;
}
