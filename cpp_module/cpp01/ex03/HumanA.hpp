#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(std::string name, class Weapon &weapon);
        ~HumanA();
        void attack();
    private:
        std::string name;
        class Weapon &weapon;
};

#endif