#include "Zombie.hpp"

int main(void)
{
	Zombie *glam;

    randomChump("Pinky");

	glam = newZombie("Glam");
	glam->announce();
	delete glam;
	
    return (0);
}
