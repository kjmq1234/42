#include <iostream>
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
    // MateriaSource 생성 및 Materia 학습
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    std::cout << std::endl;

    // Character 생성
    Character* me = new Character("me");
    Character* bob = new Character("bob");

    // Materia 생성 및 장착
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    std::cout << std::endl;

    // // Materia 사용 및 해제
    me->unequip(0);
    me->use(0, *bob);
    std::cout << std::endl;

    for (int i = 0; i < 50; i++) {
        tmp = src->createMateria("cure");
        me->equip(tmp);
        me->unequip(0);
    }
    std::cout << std::endl;

    // 복사 생성자를 사용하여 Character 복사
    Character* clone = new Character(*me);
    clone->equip(src->createMateria("ice"));
    clone->use(0, *bob);
    std::cout << std::endl;

    // 복사 할당 연산자를 사용하여 Character 복사
    Character* assigned = new Character();
    *assigned = *me;
    assigned->equip(src->createMateria("cure"));
    assigned->use(0, *bob);
    std::cout << std::endl;

    // 메모리 해제
    delete bob;
    delete me;
    delete clone;
    delete assigned;
    delete src;

}