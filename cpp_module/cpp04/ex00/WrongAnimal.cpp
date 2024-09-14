#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal default structor" << std::endl;
    this->type = "WrongAnimal default WrongAnimal";
}

WrongAnimal::WrongAnimal(std::string type)
{
    this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &WrongAnimal)
{
    std::cout << "WrongAnimal copy constructor" << std::endl;
    this->type = WrongAnimal.type;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal default destructor" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &WrongAnimal)
{
    std::cout << "WrongAnimal assignation operator" << std::endl;
    this->type =  WrongAnimal.type;

    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal is not live" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}