#pragma once

#include <iostream>
#include <vector>

using namespace std;


struct Dog 
{
	void sayHello()
	{
		cout << "Hello i am Dog\n";
	}
};

struct Cat
{
	void sayHello()
	{
		cout << "Hello i am Cat\n";
	}
};

struct Rabbit
{
	void sayHello()
	{
		cout << "Hello i am Rabbit\n";
	}
};



struct AnimalWrapper
{
	template <typename T>
	AnimalWrapper(T animal) : wrappedAnimal_{ std::make_shared<Animal<T>>(std::move(animal)) }
	{
	};

	void sayHello()
	{
		wrappedAnimal_->sayHello();
	}

	struct IAnimal
	{
		virtual void sayHello() = 0;
	};

	template <typename T>
	struct Animal : IAnimal
	{
		T animal_;

		Animal(T animal) : animal_{ std::move(animal) }
		{
		}

		void sayHello() override
		{
			animal_.sayHello(); // duck typing
		}
	};

private:

	std::shared_ptr<IAnimal> wrappedAnimal_;
};




void TemplatePolymorhismExample()
{
	AnimalWrapper dog{ Dog{} };
	AnimalWrapper cat{ Cat{} };
	AnimalWrapper rabbit{ Rabbit{} };

	std::vector<AnimalWrapper> animals{ dog, cat, rabbit };

	for (auto&& animal : animals)
	{
		animal.sayHello();
	}
}