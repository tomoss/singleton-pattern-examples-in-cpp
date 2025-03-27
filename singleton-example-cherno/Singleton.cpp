#include "Singleton.h"
#include <iostream>

/* it's private to this file */
static Singleton* instance = nullptr;

Singleton& Singleton::getInstance()
{
    if (!instance)
    {
        instance = new Singleton(); 
    }
    return *instance;
}

void Singleton::delInstance()
{
    if (instance)
    {
        delete instance;
        instance = nullptr;
    }
}

void Singleton::func()
{
    std::cout << "Hello !" << std::endl;
}
Singleton::~Singleton()
{
    std::cout << "Singleton destroyed" << std::endl;
}

Singleton::Singleton()
{
    std::cout << "Singleton created" << std::endl;
}
