#include "phonebook.hpp"

Contact::Contact()
{
	name = "";
	lastname = "";
	nickname = "";
	number = "";
	darkestSecret = "";
}
Contact::Contact(std::string name, std::string lastname, std::string nickname, std::string number, std::string darkestSecret)
{
	this->name = name;
	this->lastname = lastname;
	this->nickname = nickname;
	this->number = number;
	this->darkestSecret = darkestSecret;
}
void Contact::longinfo()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Lastname: " << lastname << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Number: " << number << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

void Contact::shortinfo(int i)
{
	std::cout << std::setw(10) << i << "|";
	std::cout << std::setw(10) << name.substr(0, 10) << "|";
	std::cout << std::setw(10) << lastname.substr(0, 10) << "|";
	std::cout << std::setw(10) << nickname.substr(0, 10) << std::endl;
}