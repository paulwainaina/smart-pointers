#include <iostream>
#include <memory>
class Unique{
public:
	Unique() {
		std::cout << "Unique_ptr Created" << std::endl;
	}
	~Unique() {
		std::cout << "Unique_ptr Destroyed" << std::endl;
	}
};
class shared {
public:
	shared() {
		std::cout << "shared_ptr Created" << std::endl;
	}
	~shared() {
		std::cout << "shared_ptr Destroyed" << std::endl;
	}
};
int main() {
	/* 1. Unique smart pointers
		They can not be shared and are destroyed once out of scope
		Little overhead
	*/
	{
		std::unique_ptr<Unique> entity = std::make_unique<Unique>(); //make unique handles exceptions hence avoid dangling pointers
		//std::unique_ptr<Unique> copy = entity;
	}

	/* 2. shared smart pointers
		They can be shared and are destroyed once out of scope
		They use a reference counter to keep track of the copies
		Avoid using new
	*/
	{	std::shared_ptr<shared> copy;

		{
			std::shared_ptr<shared> shareentity = std::make_shared<shared>(); //make unique handles exceptions hence avoid dangling pointers
			copy = shareentity;
		}

	}

	/* 3. weak pointers
			They work the same as shared pointer but do not increase reference counter
			Check if the pointer is still valid or awake
	*/
	{	std::weak_ptr<shared> copy;

		{
			std::shared_ptr<shared> shareentity = std::make_shared<shared>(); //make unique handles exceptions hence avoid dangling pointers
			copy = shareentity;
		}

	}


	return 0;
}