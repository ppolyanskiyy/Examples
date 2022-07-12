#pragma once

#include <iostream>
#include <vector>

using namespace std;

struct IAnimal
{
	virtual void sayHello() = 0;
};


struct Dog : IAnimal
{
	void sayHello() override
	{
		cout << "Hello i am Dog\n";
	}
};

struct Cat : IAnimal
{
	void sayHello() override
	{
		cout << "Hello i am Cat\n";
	}
};

struct Rabbit : IAnimal
{
	void sayHello() override
	{
		cout << "Hello i am Rabbit\n";
	}
};




void PolymorhismExample()
{
	IAnimal* dog = new Dog();
	IAnimal* cat = new Cat();
	IAnimal* rabbit = new Rabbit();

	std::vector<IAnimal*> animals{ dog, cat, rabbit };

	for (auto&& animal : animals)
	{
		animal->sayHello();
	}


	// What if Dog, Cat, Rabbit doesn't have any common class???
}