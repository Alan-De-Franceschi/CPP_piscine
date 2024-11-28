#include "PhoneBook.hpp"

std::string	usr_input(void)
{
	std::string input;
	system("clear");
	std::cout << "Phonebook> " << std::flush;
	if (std::cin.eof())
		return ("ctrl-D");
	std::getline(std::cin, input);
	return (input);
}

int	main(void)
{
	PhoneBook	phone_book;

	while (1)
	{
		std::string input = usr_input();
		if (input.compare("ctrl-D") == 0)
			return (system("clear"), 0);
		else if (input.compare("EXIT") == 0)
		{
			system("clear");
			std::cout << "So long o7 !" << std::endl;
			break ;
		}
		else if (input.compare("ADD") == 0)
			phone_book.add_contact();
		else if (input.compare("SEARCH") == 0)
		{
			if(phone_book.search_contact() == 1)
				return (system("clear"), 0);
		}
	}
	return (system("clear"), 0);
}
