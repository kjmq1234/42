#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_j = new WrongCat();

	std::cout << wrong_j->getType() << " " << std::endl;
	wrong_j->makeSound();
	wrong_meta->makeSound();

	delete meta;
	delete j;
	delete i;
	delete wrong_meta;
	delete wrong_j;
}