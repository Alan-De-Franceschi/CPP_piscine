#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include "Contact.hpp"

# define CLEAR "\33[2K\r"
# define UP "\033[A"

class PhoneBook
{
	public:
		Contact	Contacts[8];

		PhoneBook(void);
		~PhoneBook(void);

		int		add_contact(void);
		int		search_contact(void) const;

	private:
		int		_index;
		int		_size;
};

#endif