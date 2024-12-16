#include "Zombie.hpp"

int main(int ac, char **av)
{
	Zombie *horde;
	int		N;

	if (ac != 3)
		return (1);
	N = std::atoi(av[1]);
	if (N == -1 || N < 0)
		return (1);
	horde = zombieHorde(N, av[2]);
	for (int i = 0; i < N; i++)
	{
		std::cout 
			<< i + 1 
			<< " " 
			<< std::flush;
		horde[i].announce();
	}
	delete [] horde;
    return (0);
}
