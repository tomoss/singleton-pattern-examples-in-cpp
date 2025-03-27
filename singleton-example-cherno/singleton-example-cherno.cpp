#include <iostream>
#include "Singleton.h"

/*
* Cherno example with instance as static 'global' variable
* Lazy initialization
* Singleton is created only after first call of getInstance() and destroyed by calling delInstance()
* Thread-safety not guaranteed
*/

int main()
{
    std::cout << "--- main start ---" << std::endl;

    Singleton::getInstance().func();

    Singleton::delInstance();

    std::cout << "--- main end ---" << std::endl;
}