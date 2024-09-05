#include "FragTrap.hpp"

int main(void)
{
    FragTrap fragTrap1("FragTrap1");
    FragTrap fragTrap2("FragTrap2");
    std::cout << std::endl;

    fragTrap1.attack("FragTrap2");
    fragTrap2.takeDamage(20);
    fragTrap2.beRepaired(10);
    std::cout << std::endl;

    fragTrap1.highFivesGuys();
    std::cout << std::endl;
}