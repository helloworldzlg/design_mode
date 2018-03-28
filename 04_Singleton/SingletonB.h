#pragma once
#include "Singleton.h"

class SingletonB : public Singleton
{
    friend class Singleton;

public:
    void show()
    {
        cout << "SingletonB" << endl;
    }

private:
    SingletonB()
    {
        cout << "constructor of SingletonB" << endl;
    }
};