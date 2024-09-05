#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap clapTrap("ClapTrap");
    ClapTrap clapTrap2("ClapTrap2");
    std::cout << std::endl;

    clapTrap.attack("clapTrap2");
    clapTrap2.takeDamage(5);
    clapTrap2.beRepaired(3);
    std::cout << std::endl;

    clapTrap2.attack("clapTrap");
    clapTrap.takeDamage(10);
    std::cout << std::endl;
    
    clapTrap.attack("clapTrap2");
    clapTrap.beRepaired(7);
    clapTrap.attack("clapTrap2");
    std::cout << std::endl;

    for (int i = 0; i < 8; i++)
        clapTrap.attack("clapTrap2");
    std::cout << std::endl;
}