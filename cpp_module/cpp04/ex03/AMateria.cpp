#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {}
AMateria::AMateria(std::string const & type) : _type(type) {}
AMateria::AMateria(AMateria const & src) { *this = src; }
AMateria & AMateria::operator=(AMateria const & src) { _type = src._type; return *this; }
AMateria::~AMateria() {}

std::string const & AMateria::getType() const { 
    return _type; 
}

void AMateria::use(ICharacter& target) {
    std::cout << "* Interface " << target.getName() << " * " << std::endl;
}