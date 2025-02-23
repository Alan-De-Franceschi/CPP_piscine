# include <iostream>
# include <string>

int	main(void)
{
	std::string	str 		= "HI THIS IS BRAIN";
	std::string *stringPTR 	= &str;
	std::string &stringREF	= str;

	std::cout << "str address:               " << &str << std::endl;
	std::cout << "address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "address held by stringREF: " << &stringREF << std::endl << std::endl;

	std::cout << "str value:                  " << str << std::endl;
	std::cout << "value pointed by stringPTR: " << *stringPTR << std::endl;
	std::cout << "value pointed by stringREF: " << stringREF << std::endl;

	return (0);
}
