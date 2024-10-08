#include "Cat.hpp"

Cat::Cat() : Animal("Default Animal")
{
    this->type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
    this->type = cat.type;
    std::cout << "Cat assignation operator called" << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Mow Mow" << std::endl;
}
