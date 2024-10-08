#include "Character.hpp"



Character::Character() : _name("default") {
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
    trashsIndex = 0;
}

Character::Character(std::string const & name) : _name(name) {
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
    trashsIndex = 0;
}

Character::Character(Character const & src) {
    for (int i = 0; i < 4; i++) {
        if (_inventory[i]) {
            delete _inventory[i];
            _inventory[i] = NULL;
        }
    }
    *this = src;
}

Character & Character::operator=(Character const & src) {
    for (int i = 0; i < 4; i++) {
        if (_inventory[i])
        {
            delete _inventory[i];
            _inventory[i] = NULL;
        }
    }
    for (int i = 0; i < trashsIndex; i++) {
        if (src.trashs[i])
            this->trashs[i] = src.trashs[i];
    }

    this->_name = src._name;
    trashsIndex = src.trashsIndex;
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (_inventory[i])
            delete _inventory[i];
    }
    for (int i = 0; i < trashsIndex; i++) {
        if (trashs[i])
            delete trashs[i];
    }
}

std::string const & Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (!_inventory[i]) {
            _inventory[i] = m;
            return;
        }
    }
    std::cout << "Inventory is full" << std::endl;
    delete m;
}

void Character::unequip(int idx) {
    if (trashsIndex >= 50)
    {
        std::cout << "Trash is full" << std::endl;
        return;
    }
    if (idx >= 0 && idx < 4) {
        if (_inventory[idx])
        {
            trashs[trashsIndex++] = _inventory[idx];
            _inventory[idx] = NULL;
        }
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4) {
        if (_inventory[idx])
            _inventory[idx]->use(target);
        else
            std::cout << "No materia in this slot" << std::endl;
    }
}