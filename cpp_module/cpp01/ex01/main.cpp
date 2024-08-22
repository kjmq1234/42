#include "Zombie.hpp"

int main()
{
    Zombie  *zombies = ZombieHorde(5, "Zombie");
    for (int i = 0; i < 5; i++)
        zombies[i].announce();
    delete[] zombies;
}