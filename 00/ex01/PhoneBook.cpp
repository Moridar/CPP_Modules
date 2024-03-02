#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
}

void PhoneBook::rotatePhoneBook()
{
	for (int i = 7; i > 0; i--)
		phonebook[i] = phonebook[i - 1];
}
void PhoneBook::addContact(Contact c)
{
	if (index < 8)
		index++;
	rotatePhoneBook();
	phonebook[0] = c;
}
void PhoneBook::printContact(int i)
{
	phonebook[i].printContact();
}
void PhoneBook::printPhoneBook()
{
	int i = -1;
	while (++i < index)
		phonebook[i].quickPrint(i);
}

bool PhoneBook::isEmpty()
{
	if (index == 0)
		return true;
	return false;
}