#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    this->brain = new Brain();
    this->type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal("Default Animal")
{
    this->brain = new Brain(*dog.brain);
    this->type = dog.type;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
    if (this == &dog)
        return *this;
    delete this->brain;
    this->brain = new Brain(*dog.brain);
    this->type = dog.type;
    std::cout << "Dog assignation operator called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Wal Wal" << std::endl;
}

Brain *Dog::getBrain() const
{
    return this->brain;
}