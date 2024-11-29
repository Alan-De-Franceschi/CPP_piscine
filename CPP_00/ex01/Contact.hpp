#ifndef CONTACT_H
# define CONTACT_H

#include <string>

class Contact 
{
	public:
		std::string	name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone;
		std::string	secret;

		Contact(void);
		~Contact(void);
};

#endif