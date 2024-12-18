#include "File.hpp"

int main(int ac, char **av)
{
	if (ac < 4)
		return (std::cout << "too few arguments" << std::endl, 1);
	if (ac > 4)
		return (std::cout << "too much arguments" << std::endl, 1);

    File    file(av[1]);
	if (file.getStatus() == 1)
		return (1);

    return (0);
}
