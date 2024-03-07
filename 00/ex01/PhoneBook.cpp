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
void PhoneBook::add()
{
	std::string name, lastname, nickname, number, darkestSecret;
	std::cout << "Enter name: ";
	std::cin >> name;
	std::cout << "Enter lastname: ";
	std::cin >> lastname;
	std::cout << "Enter nickname: ";
	std::cin >> nickname;
	std::cout << "Enter number: ";
	std::cin >> number;
	std::cout << "Enter darkest secret: ";
	std::cin >> darkestSecret;
	if (contacts < 8)
		contacts++;
	rotatePhoneBook();
	phonebook[0] = Contact(name, lastname, nickname, number, darkestSecret);
}
void PhoneBook::get(int i)
{
	if (i >=0 && i < contacts)
		phonebook[i].longinfo();
	else
		std::cout << "The index doesnt exist" << std::endl;
}
int PhoneBook::overview()
{
	if (this->isEmpty())
	{
		std::cout << "Phonebook is empty." << std::endl;
		return (0);
	}
	int i = -1;
	while (++i < contacts)
		phonebook[i].shortinfo(i);
	return (1);
}

bool PhoneBook::isEmpty()
{
	if (contacts == 0)
		return true;
	return false;
}
void PhoneBook::search()
{
	if (this->overview() == 0)
		return ;
	std::cout << "Enter index: ";
	int index;
	std::cin >> index;
	if (std::cin.fail()) 
	{
			std::cin.clear(); // clear the fail state
			std::cout << "Invalid input. Please enter a number." << std::endl;
	} 
	else
		this->get(index);
}

void PhoneBook::open()
{
	std::string command;

	while (1)
	{
		std::cout << "Enter a command: ";
		std::cin >> command;
		if (command == "ADD")
			this->add();
		if (command == "SEARCH")
			this->search();
		if (command == "EXIT")
			break;
	}
}