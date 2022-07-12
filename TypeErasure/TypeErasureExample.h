#pragma once

#include <memory>

struct Wrapper
{
	template <typename T>
	Wrapper(T t) : object_{ std::make_shared<TypeErasedObject<T>>(std::move(t)) } {}

	void printInfo()
	{
		object_->printInfo();
	}

	struct TypeErasedObjectBase
	{
		virtual ~TypeErasedObjectBase() = default;
		virtual void printInfo() = 0;
	};

	template <typename T>
	struct TypeErasedObject : TypeErasedObjectBase
	{
		T typeErasedObject_;

		TypeErasedObject(T typeErasedObject) : typeErasedObject_{ std::move(typeErasedObject) } {};

		void printInfo() override 
		{
			std::cout << typeid(T).name() << std::endl;
		}
	};

	std::shared_ptr<TypeErasedObjectBase> object_;
};



void TypeErasureExample()
{
	Wrapper wrappedInt{ 10 };
	Wrapper wrappedBool{ true };
	Wrapper wrappedFloat{ 20.f };

	std::vector wrappedObjects{ wrappedInt, wrappedBool, wrappedFloat };

	for (auto&& obj : wrappedObjects)
	{
		obj.printInfo();
	}
}