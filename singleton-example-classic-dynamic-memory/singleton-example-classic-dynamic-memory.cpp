#include <iostream>
#include <string>

/*
* Example with static pointer member variable
* Dynamic memory allocation
* Lazy initialization
* Singleton is created only after first call of getInstance() and destroyed by calling delInstance()
* Thread-safety not guaranteed
*/

class Singleton
{
public:
    Singleton(Singleton& other) = delete; /* Deleted copy constructor. */
    Singleton& operator=(const Singleton&) = delete; /* Deleted copy assigment operator. */

    static Singleton* getInstance() /* Created a public static method to allocate memory and get the static instance. */
    {
        if (!instance)
        {
            instance = new Singleton();
        }
        return instance;
    }

    static void delInstance() /* Created a public static method to deallocate memory */
    {
        if (instance)
        {
            delete instance;
            instance = nullptr;
        }
    }

    void func() { std::cout << "Hello !" << std::endl; }
    ~Singleton() { std::cout << "Singleton destroyed" << std::endl; }

private:
    Singleton() { std::cout << "Singleton created" << std::endl; }; /* Made constructor private. */
    static Singleton* instance;  /* Declared static instance as member variable. */
};

Singleton* Singleton::instance = nullptr; /* Defined static instance outside class. */

int main()
{
    std::cout << "--- main start ---" << std::endl;

    Singleton::getInstance()->func();
    Singleton::getInstance()->func();
    Singleton::delInstance();

    std::cout << "--- main end ---" << std::endl;
}

