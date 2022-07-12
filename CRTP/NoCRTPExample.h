#pragma once

#include <iostream>

using namespace std;

struct IAnimal
{
	virtual void sayHello() = 0;
	virtual IAnimal* clone() = 0;
};


struct AnimalBase : IAnimal
{
	void greet(const std::string& animalName)
	{
		cout << "Hello i am " << animalName << "\n";
	}
};


struct Dog : AnimalBase
{
	void sayHello() override
	{
		greet("Dog");
	}

	IAnimal* clone() override // dynamic polymorphism
	{
		return new Dog(*this); // dublication
	}

};

struct Cat : AnimalBase
{
	void sayHello() override
	{
		greet("Cat");
	}

	IAnimal* clone() override // dynamic polymorphism
	{
		return new Cat(*this);  // dublication
	}
};

struct Rabbit : AnimalBase
{
	void sayHello() override
	{
		greet("Rabbit");

	}

	IAnimal* clone() override // dynamic polymorphism
	{
		return new Rabbit(*this);  // dublication
	}
};