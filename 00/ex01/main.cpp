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
			pb.add();
		else if (command == "SEARCH")
		{
			if (pb.isEmpty())
			{
				std::cout << "Phonebook is empty." << std::endl;
				continue;
			}
			pb.overview();
			std::cout << "Enter index: ";
			int index;
			std::cin >> index;
			if (std::cin.fail()) 
			{
       			 std::cin.clear(); // clear the fail state
       			 std::cout << "Invalid input. Please enter a number." << std::endl;
  		  	} 
			else
				pb.get(index);
			command = "";
		}
		else if (command == "EXIT")
			break;
	}
	return 0;
}