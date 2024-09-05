#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap scavTrap1("ScavTrap1");
    ScavTrap scavTrap2("ScavTrap2");
    std::cout << std::endl;

    scavTrap1.attack("ScavTrap2");
    scavTrap2.takeDamage(20);
    scavTrap2.beRepaired(10);
    std::cout << std::endl;

    scavTrap1.guardGate();
    std::cout << std::endl;
}