#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap parameter constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = clapTrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
    std::cout << "ClapTrap assignation operator called" << std::endl;
    _name = clapTrap._name;
    _hitPoints = clapTrap._hitPoints;
    _energyPoints = clapTrap._energyPoints;
    _attackDamage = clapTrap._attackDamage;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->_energyPoints < 1)
    {
        std::cout << "ClapTrap " << this->_name << " has no energy points left!" << std::endl;
        return;
    }
    if (_hitPoints < 1)
    {
        std::cout << "ClapTrap " << this->_name << " has died!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount >= this->_hitPoints)
    {
        std::cout << "ClapTrap " << _name << " takes " << this->_hitPoints << " points of damage!" << std::endl;
        std::cout << "ClapTrap " << _name << " has died!" << std::endl;
        this->_hitPoints = 0;
        return;
    }
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
    this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints < 1)
    {
        std::cout << "ClapTrap " << this->_name << " has no energy points left!" << std::endl;
        return;
    }

    std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points!" << std::endl;
    this->_hitPoints += amount;
    this->_energyPoints--;
}