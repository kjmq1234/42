#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "animal default structor" << std::endl;
    this->type = "animal default Animal";
}

Animal::Animal(std::string type)
{
    this->type = type;
}

Animal::Animal(const Animal &animal)
{
    std::cout << "animal copy constructor" << std::endl;
    this->type = animal.type;
}

Animal::~Animal()
{
    std::cout << "default destructor" << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
    std::cout << "Animal assignation operator" << std::endl;
    this->type =  animal.type;

    return *this;
}

void Animal::makeSound() const
{
    std::cout << "animal is not live" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}