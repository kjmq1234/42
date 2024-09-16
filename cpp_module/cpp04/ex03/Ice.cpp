#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
    this->_type = "ice";
}

Ice::Ice(Ice const & src) {
    *this = src;
}

Ice & Ice::operator=(Ice const & src) {
    this->_type = src._type;
    return *this;
}

Ice::~Ice() {}

AMateria* Ice::clone() const {
    return new Ice();
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}