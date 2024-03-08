#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cctype>
#include "Contact.hpp"


class PhoneBook
{
	private:
		Contact phonebook[8];
		int contacts;
		void rotatePhoneBook();
		bool isEmpty();
		void add();
		void search();
		int get(int index);
		int overview();
	public:
		PhoneBook();
		void open();	
};

#endif