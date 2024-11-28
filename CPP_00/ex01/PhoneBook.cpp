#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _index(0), _size(0)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

int	fill_infos(std::string & str)
{
	std::string	buf;

	while(buf.empty() || buf.find('\t') != std::string::npos)
	{
		if (std::cin.eof())
			return (1);
		std::getline(std::cin, buf);
		if (buf.length() > 0 && buf.find('\t') == std::string::npos)
		{
			str = buf;
			break ;
		}
		std::cout << UP << CLEAR << std::flush;
	}
	return (0);
}

int	fill_contact(Contact & instance)
{
	std::string	buf;

	system("clear");
	std::cout << CLEAR << "Please enter contact infos:" << std::endl;
	std::cout << CLEAR << "NAME: " << std::endl;
	if (fill_infos(instance.name) == 1)
		return (1);
	std::cout << UP << CLEAR << UP << CLEAR << "LAST NAME: " << std::endl;
	if (fill_infos(instance.last_name) == 1)
		return (1);
	std::cout << UP << CLEAR << UP << CLEAR << "NICKNAME: " << std::endl;
	if (fill_infos(instance.nickname) == 1)
		return (1);
	std::cout << UP << CLEAR << UP << CLEAR << "PHONE: " << std::endl;
	if (fill_infos(instance.phone) == 1)
		return (1);
	std::cout << UP << CLEAR << UP << CLEAR << "SECRET: " << std::endl;
	if (fill_infos(instance.secret) == 1)
		return (1);
	return (0);
}

int	PhoneBook::add_contact(void)
{
	if (this->_index == 8)
		this->_index = 0;
	if (fill_contact(this->Contacts[this->_index]) == 1)
		return (1);
	this->_index += 1;
	if (this->_size < 8)
		this->_size += 1;
	return (0);
}

void	print_infos(std::string str)
{
	std::cout << "|" << std::flush;
	if (str.length() > 10)
		str = str.substr(0, 9) + ".";
	std::cout << std::setfill(' ') << std::setw(10) << str << std::flush;
	return ;
}

int	print_contact(const Contact & instance)
{
	std::string buf;

	system("clear");
	std::cout << "NAME     : " << instance.name << std::endl; 
	std::cout << "LAST_NAME: " << instance.last_name << std::endl;
	std::cout << "NICKNAME : " << instance.nickname << std::endl;
	std::cout << "PHONE    : " << instance.phone << std::endl;
	std::cout << "SECRET   : " << instance.secret << std::endl << std::endl;
	std::cout << "-- Press enter to continue --" << std::flush;
	std::getline(std::cin, buf);
	if (std::cin.eof())
		return (1);
	return (0);
}

void	print_contact_list(int size, Contact const (& contacts )[8])
{
	std::cout << "|     INDEX|      NAME| LAST NAME|  NICKNAME|" << std::endl;
	for (int i = 0; i < size; ++i)
	{
		std::cout << "|" << "         " << i << std::flush;
		print_infos(contacts[i].name);
		print_infos(contacts[i].last_name);
		print_infos(contacts[i].nickname);
		std::cout << "|" << std::endl;
	}
	std::cout << std::endl << std::endl;
	return ;
}

int	PhoneBook::search_contact(void) const
{
	std::string	buf;
	int i = -1;

	if (_size == 0)
	{
		system("clear");
		std::cout << "-- 0 contacts --" << std::endl << std::endl;
		std::cout << "-- Press enter to continue --" << std::flush;
		std::getline(std::cin, buf);
		if (std::cin.eof())
			return (1);
		return (0);
	}
	else
	{
		while (buf.length() != 1 || !isdigit(buf[0]) || i < 0 || i > 8 || i >= this->_size)
		{
			system("clear");
			print_contact_list(this->_size, this->Contacts);
			std::cout << "Please enter contact index:" << std::flush;
			if (std::cin.eof())
				return (1);
			std::getline(std::cin, buf);
			std::istringstream(buf) >> i;
			if (buf.length() == 1 && isdigit(buf[0]) && i >= 0 && i <= 8 && i < this->_size)
			{
				if (print_contact(this->Contacts[i]) == 1)
					return (1);
				break ;
			}
		}
	}
	return (0);
}
