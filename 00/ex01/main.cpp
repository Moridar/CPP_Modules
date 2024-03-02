#include "phonebook.hpp"

int main(void)
{
	PhoneBook pb;
	std::string command;
	while (1)
	{
		command = "";
		std::cout << "Enter a command: ";
		std::cin >> command;
		if (command == "ADD")
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
			Contact c(name, lastname, nickname, number, darkestSecret);
			pb.addContact(c);
		}
		else if (command == "SEARCH")
		{
			if (pb.isEmpty())
			{
				std::cout << "Phonebook is empty." << std::endl;
				continue;
			}
			pb.printPhoneBook();
			std::cout << "Enter index: ";
			int index;
			std::cin >> index;
			if (std::cin.fail()) 
			{
       			 std::cin.clear(); // clear the fail state
       			 std::cout << "Invalid input. Please enter a number." << std::endl;
  		  	} 
			else
				pb.printContact(index);
			command = "";
		}
		else if (command == "EXIT")
			break;
	}
	return 0;
}