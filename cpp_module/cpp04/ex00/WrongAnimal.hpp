#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal &WrongAnimal);
        WrongAnimal &operator=(const WrongAnimal &WrongAnimal);
        ~WrongAnimal();
        void makeSound() const;
        std::string getType() const;
};

#endif