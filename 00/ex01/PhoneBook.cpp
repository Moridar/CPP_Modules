#include "phonebook.hpp"

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
}
void PhoneBook::overview()
{
	int i = -1;
	while (++i < contacts)
		phonebook[i].shortinfo(i);
}

bool PhoneBook::isEmpty()
{
	if (contacts == 0)
		return true;
	return false;
}