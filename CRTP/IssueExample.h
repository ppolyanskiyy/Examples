#pragma once

#include <iostream>

using namespace std;

struct IAnimal
{
	virtual void sayHello() = 0;

};



struct Dog : IAnimal
{
	void sayHello() override
	{
		cout << "Hello";	// duplication
		cout << "i am";		// duplication
		cout << "Dog";
		cout << "\n";		// duplication
	}

};

struct Cat : IAnimal
{
	void sayHello() override
	{
		cout << "Hello";	// duplication
		cout << "i am";		// duplication
		cout << "Cat";
		cout << "\n";		// duplication
	}

};

struct Rabbit : IAnimal
{
	void sayHello() override
	{
		cout << "Hello";	// duplication
		cout << "i am";		// duplication
		cout << "Rabbit";
		cout << "\n";		// duplication
	}

};





IAnimal* getAnimal()
{
	// return new Dog();
	// return new Cat();
	return new Rabbit();

}

void VirtualCopyProblem()
{
	// We have any object stored in IAnimal pointer class
	IAnimal* animal = getAnimal();

	// How to create copy of that object?
	// IAnimal* animalCopy = new IAnimal(*animal); - won't compile
}