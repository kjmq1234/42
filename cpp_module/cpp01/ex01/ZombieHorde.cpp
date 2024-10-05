#include "Zombie.hpp"

Zombie*	ZombieHorde(int N, std::string name)
{
    Zombie*	zombies = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        Zombie*	zombie = new Zombie();
        zombie->setName(name + std::to_string(i + 1));
        zombies[i] = *zombie;
        delete zombie;
    }
    return (zombies);
}