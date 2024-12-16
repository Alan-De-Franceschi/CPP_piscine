#include "Zombie.hpp"

int main(void)
{
	Zombie *horde;

	horde = zombieHorde(10, "Pinky");

	for (int i = 0; i < 10; i++)
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
