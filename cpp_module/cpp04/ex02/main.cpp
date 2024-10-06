#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	Animal *animal = new Dog();
	// Animal *animal = new Animal();
	animal->makeSound();
	delete animal;
}