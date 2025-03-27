#include <iostream>

/*
* Meyer’s Singleton - Instance as static local variable
* Lazy initialization
* Singleton is created only after first call of getInstance() and destroyed after main() call
* Thread-safe - Thread safety is guaranteed since C++11. A function-local static variable is initialized exactly once, even in a multi-threaded environment.
*/

class Singleton
{
public:
	Singleton(const Singleton&) = delete; /* Deleted copy constructor. */
	Singleton& operator=(const Singleton&) = delete; /* Deleted copy assigment operator. */

	static Singleton& getInstance()
	{
		static Singleton instance; /* Static local variable - is instantiated only once */
		return instance;
	}

	void func() { std::cout << "Hello !" << std::endl; }
	~Singleton() { std::cout << "Singleton Destroyed!\n"; }

private:
	Singleton() { std::cout << "Singleton created" << std::endl; }; /* Made constructor private. */
};

int main()
{
	std::cout << "--- main start ---" << std::endl;

	Singleton::getInstance().func();

	std::cout << "--- main end ---" << std::endl;
}