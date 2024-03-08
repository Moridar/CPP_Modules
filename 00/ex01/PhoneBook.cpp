#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	contacts = 0;
}

void PhoneBook::rotatePhoneBook()
{
	for (int i = 7; i > 0; i--)
		phonebook[i] = phonebook[i - 1];
}

static int getinput(std::string key, std::string *pointer)
{
	std::cout << "Enter " + key + ":";
	std::getline(std::cin, *pointer);
	if (std::cin.eof())
		std::exit(0);
	if (pointer->empty())
		return (0);
	return (1);
}

void PhoneBook::add()
{
	std::string name, lastname, nickname, number, darkestSecret;
	
	while (!getinput("name", &name))
		;
	while (!getinput("lastname", &lastname))
		;
	while (!getinput("nickname", &nickname))
		;
	while (!getinput("number", &number))
		;
	while (!getinput("darkest secret", &darkestSecret))
		;
	if (contacts < 8)
		contacts++;
	rotatePhoneBook();
	phonebook[0] = Contact(name, lastname, nickname, number, darkestSecret);
}

int PhoneBook::get(int i)
{
	if (i >=0 && i < contacts)
	{
		phonebook[i].longinfo();
		return (1);
	}
	std::cout << "The index doesnt exist" << std::endl;
	return (0);
}

bool PhoneBook::isEmpty()
{
	return (contacts == 0);
}

int PhoneBook::overview()
{
	if (this->isEmpty())
	{
		std::cout << "Phonebook is empty." << std::endl;
		return (0);
	}
	std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First name" << "|"
		<< std::setw(10) << "Last name" << "|" << std::setw(10) << "Nick name" << std::endl;
	int i = -1;
	while (++i < contacts)
		phonebook[i].shortinfo(i);
	return (1);
}

void PhoneBook::search()
{
	int index;
	
	if (this->overview() == 0)
		return ;
	while (1)
	{
		std::cout << "Enter index: ";
		std::cin >> index;
		if (std::cin.eof())
			break ;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Invalid input. Please enter a number." << std::endl;
		}
		else if (this->get(index))
		{
			std::cin.ignore(10000, '\n');
			break ;
		}
	} 
	
}

void PhoneBook::open()
{
	std::string command;

	while (1)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);
		if (command == "ADD")
			this->add();
		if (command == "SEARCH")
			this->search();
		if (command == "EXIT")
			break;
		if (std::cin.eof())
			break;
	}
}
