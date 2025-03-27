#include <iostream>
#include <mutex>
#include <future>

/*
* Singleton with Double-Checked Locking
* Lazy initialization
* Singleton is created only after first call of getInstance() and destroyed by calling delInstance()
* DCLP is designed to add efficient thread-safety to initialization of a shared resource (such as a Singleton), but it has a problem: it’s not reliable
* DCLP can fail for different reasons
*/

class Singleton
{
public:
    Singleton(Singleton& other) = delete; /* Deleted copy constructor. */
    Singleton& operator=(const Singleton&) = delete; /* Deleted copy assigment operator. */

    static Singleton* getInstance()
    {
        if (!instance)
        {
            std::lock_guard<std::mutex> lock(mtx);
            if (!instance)
            {
                instance = new Singleton();
            }
        }
        return instance;
    }

    static void delInstance()
    {
        if (instance)
        {
            std::lock_guard<std::mutex> lock(mtx);
            if (instance)
            {
                delete instance;
                instance = nullptr;
            }
        }
    }

    void func() { std::cout << "Hello !" << std::endl; }
    ~Singleton() { std::cout << "Singleton destroyed" << std::endl; }

private:
    Singleton() { std::cout << "Singleton created" << std::endl; }; /* Made constructor private. */
    static Singleton* instance; /* Declared static instance as member variable. */
    static std::mutex mtx; /* Declared a static mutex as a member varaible. */
};

Singleton* Singleton::instance = nullptr; /* Defined static instance outside class. */
std::mutex Singleton::mtx;  /* Defined static mutex outside class. */

int main()
{
    Singleton::getInstance()->func();

    auto async1 = std::async(std::launch::async, []()
    {
            Singleton::getInstance()->func();
    });

    auto async2 = std::async(std::launch::async, []()
        {
            Singleton::getInstance()->func();
        });

    async1.wait();
    async2.wait();

    Singleton::delInstance();
}


