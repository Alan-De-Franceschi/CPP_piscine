#include "Sed.hpp"

int main(int ac, char **av)
{
	if (ac < 4)
		return (std::cout << "too few arguments" << std::endl, 1);
	if (ac > 4)
		return (std::cout << "too much arguments" << std::endl, 1);

	std::string	s1 = av[2];
	std::string	s2 = av[3];
	sed(av[1], s1, s2);
    return (0);
}
