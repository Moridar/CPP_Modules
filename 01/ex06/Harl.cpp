#include "Harl.hpp"

void Harl::debug( void ) {
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup"
		" burger. I really do!" << std::endl;
	Harl::info();
}

void Harl::info( void ) {
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put"
		"enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	Harl::warning();
}

void Harl::warning( void ) {
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for"
		"years whereas you started working here since last month." << std::endl;
	Harl::error();
}

void Harl::error( void ) {
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level ) {
	
	void (Harl::*func[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int i = 0;
	while (level != levels[i] && i < 4)
		i++;
	switch (i)
	{
		case 0: (this->*func[0])();
			break;
		case 1: (this->*func[1])();
			break;
		case 2: (this->*func[2])();
			break;
		case 3: (this->*func[3])();
			break;
		default: std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
