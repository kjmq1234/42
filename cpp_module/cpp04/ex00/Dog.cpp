#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    this->type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal("Default Animal")
{
    this->type = type;
    std::cout << "Dog type constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal("Default Animal")
{
    this->type = dog.type;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
    this->type = dog.type;
    std::cout << "Dog assignation operator called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Wal Wal" << std::endl;
}