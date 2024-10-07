#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::string str;
	Animal *meta[10];

	for (size_t i = 0; i < 10; i++)
	{
		if (i % 2)
		{
			meta[i] = new Dog();
		}
		else
		{
			meta[i] = new Cat();
		}
	}
	std::cout << std::endl;
	
	for (size_t i = 0; i < 10; i++)
		delete meta[i];
	std::cout << std::endl;
	

	Dog *d = new Dog();
	Dog *d2 = new Dog();
	std::cout << std::endl;

	str = d->getBrain()->getIdea(0);
	std::cout << "Dog1's first idea is "<< str << std::endl;
	std::cout << std::endl;

	d->getBrain()->setIdea(0, "Some");
	str = d->getBrain()->getIdea(0);
	std::cout << "Dog1's first idea is "<< str << std::endl;
	std::cout << &d << std::endl;
	std::cout << std::endl;

	*d2 = *d;
	str = d2->getBrain()->getIdea(0);
	std::cout << "Dog2's first idea is "<< str << std::endl;
	std::cout << &d2 << std::endl;
	std::cout << std::endl;

	delete d;
	delete d2;
}