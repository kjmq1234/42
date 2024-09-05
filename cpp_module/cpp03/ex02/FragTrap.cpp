#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap default constructor" << std::endl;
    this->_name = "FragTrap";
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name)
{
    std::cout << "FragTrap constructor" << std::endl;
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& src)
{
    std::cout << "FragTrap copy constructor" << std::endl;
    *this = src;
}

FragTrap& FragTrap::operator=(const FragTrap& src)
{
    std::cout << "FragTrap assignation operator" << std::endl;
    this->_name = src._name;
    this->_hitPoints = src._hitPoints;
    this->_energyPoints = src._energyPoints;
    this->_attackDamage = src._attackDamage;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor" << std::endl;
}

void FragTrap::attack(std::string const &target)
{
    if (this->_energyPoints < 1)
    {
        std::cout << "FragTrap " << this->_name << " has no energy points to attack" << std::endl;
        return;
    }
    std::cout << "FragTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints--;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->_name << " requests a high five" << std::endl;
}