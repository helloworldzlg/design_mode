#pragma once
#include "Singleton.h"

class SingletonA : public Singleton
{
    friend class Singleton;

public:
    void show()
    {
        cout << "SingletonA" << endl;
    }

private:
    SingletonA()
    {
        cout << "constructor of SingletonA" << endl;
    };
};