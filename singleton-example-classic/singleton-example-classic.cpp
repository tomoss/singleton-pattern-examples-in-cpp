#include <iostream>

/*
* Example with instance as static member variable
* Eager initialization
* Singleton is created before main() and destroyed after main() call
* Thread-safety not guaranteed
*/

class Singleton
{
public:
    Singleton(const Singleton&) = delete; /* Deleted copy constructor. */
    Singleton& operator=(const Singleton&) = delete; /* Deleted copy assigment operator. */

    static Singleton& getInstance() /* Created a public static method de get the static instance. */
    {
        return instance;
    }

    void func() { std::cout << "Hello !" << std::endl; }
    ~Singleton() { std::cout << "Singleton destroyed" << std::endl; }

private:
    Singleton() { std::cout << "Singleton created" << std::endl; }; /* Made constructor private. */
    static Singleton instance;  /* Declared static instance as member variable. */
};

Singleton Singleton::instance; /* Defined static instance outside class. */

int main()
{
    std::cout << "--- main start ---" << std::endl;

    Singleton::getInstance().func();

    std::cout << "--- main end ---" << std::endl;
}
