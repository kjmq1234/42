#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap default constructor" << std::endl;
    _name = "ScavTrap";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap constructor with name" << std::endl;
    _name = name;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap)
{
    std::cout << "ScavTrap copy constructor" << std::endl;
    *this = scavTrap;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
    std::cout << "ScavTrap assignation operator" << std::endl;
    _name = scavTrap._name;
    _hitPoints = scavTrap._hitPoints;
    _energyPoints = scavTrap._energyPoints;
    _attackDamage = scavTrap._attackDamage;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
    if (this->_energyPoints < 1)
    {
        std::cout << "ScavTrap " << _name << " has no energy points to attack" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << _name << " attacks " << target << ", get" << _attackDamage << " points of damage!" << std::endl;
    this->_energyPoints--;
}