#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
    this->_type = "cure";
}

Cure::Cure(Cure const & src) {
    *this = src;
}

Cure & Cure::operator=(Cure const & src) {
    this->_type = src._type;
    return *this;
}

Cure::~Cure() {}

AMateria* Cure::clone() const {
    return new Cure();
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}