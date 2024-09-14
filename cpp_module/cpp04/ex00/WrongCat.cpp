#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat default structor" << std::endl;
    this->type = "default WrongCat";
}

WrongCat::WrongCat(std::string type)
{
    this->type = type;
}

WrongCat::WrongCat(const WrongCat &WrongCat)
{
    std::cout << "WrongCat copy constructor" << std::endl;
    this->type = WrongCat.type;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat default destructor" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &WrongCat)
{
    std::cout << "WrongCat assignation operator" << std::endl;
    this->type =  WrongCat.type;

    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat is not live" << std::endl;
}