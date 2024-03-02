#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string.h>
#include <cctype>
#include <iomanip>

class Contact
{
	private:
		std::string name;
		std::string lastname;
		std::string nickname;
		std::string number;
		std::string darkestSecret;
	public:	
		Contact();
		Contact(std::string name, std::string lastname, std::string nickname, std::string number, std::string darkestSecret);
		void printContact();
		void quickPrint(int i);
};

class PhoneBook
{
	private:
		Contact phonebook[8];
		int index;
		void rotatePhoneBook();
	public:
		PhoneBook();
		bool isEmpty();
		void addContact(Contact c);
		void printContact(int index);
		void printPhoneBook();
};

#endif