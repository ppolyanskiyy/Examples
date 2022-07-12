#pragma once

#include <iostream>

using namespace std;


struct IAnimal
{
	virtual void sayHello() = 0;
	virtual string getName() = 0;

	virtual IAnimal* clone() = 0;
};


template <typename ConcreteAnimal>
struct AnimalBase : IAnimal
{
	void sayHello() override
	{
		cout << "Hello i am " << static_cast<ConcreteAnimal*>(this)->getName() << "\n"; // Static polymorphism
	}

	IAnimal* clone() override
	{
		return new ConcreteAnimal{ static_cast<const ConcreteAnimal&>(*this) }; // Virtual copy
	}
};


struct Dog : AnimalBase<Dog>
{

	string getName() override
	{
		return "Dog";
	}
};

struct Cat : AnimalBase<Cat>
{	
	string getName() override
	{
		return "Cat";
	}
};

struct Rabbit : AnimalBase<Rabbit>
{	
	string getName() override
	{
		return "Rabbit";
	}
};



void Example()
{
	Dog dog;

	dog.sayHello();
}