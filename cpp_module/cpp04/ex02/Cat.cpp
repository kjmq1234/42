#include "Cat.hpp"

Cat::Cat() : Animal("Default Animal")
{
    this->brain = new Brain();
    this->type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal("Default Animal")
{
    this->brain = new Brain(*cat.brain);
    this->type = cat.type;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
    if (this == &cat)
        return *this;
    delete this->brain;
    this->brain = new Brain(*cat.brain);
    this->type = cat.type;
    std::cout << "Cat assignation operator called" << std::endl;
    return *this;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Mow Mow" << std::endl;
}

Brain *Cat::getBrain() const
{
    return this->brain;
}