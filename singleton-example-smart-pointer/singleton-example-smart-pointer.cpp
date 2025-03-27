#include <iostream>
#include <memory>

/*
* Singleton with unique pointer
* Lazy initialization
* Singleton is created in the first call of getInstance() and destroyed automatically after main() call
* Thread-safety not guaranteed
*/

class Singleton
{
public:
    Singleton(const Singleton&) = delete; /* Deleted copy constructor. */
    Singleton& operator=(const Singleton&) = delete; /* Deleted copy assigment operator. */

    static Singleton& getInstance()
    {
        static std::unique_ptr<Singleton> instance(new Singleton());  // Dynamic allocation with automatic cleanup
        return *instance;
    }

    void func() { std::cout << "Hello !" << std::endl; }
    ~Singleton() { std::cout << "Singleton destroyed" << std::endl; }

private:
    Singleton() { std::cout << "Singleton created" << std::endl; }; /* Made constructor private. */
};

int main()
{
    std::cout << "--- main start ---" << std::endl;

    Singleton::getInstance().func();

    std::cout << "--- main end ---" << std::endl;
}
