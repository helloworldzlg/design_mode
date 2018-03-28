#pragma once
#include <iostream>

using namespace std;

class Singleton
{
public:
    static Singleton *getInstance(const char* name);
    virtual void show() {};

protected:
    Singleton()
    {
        cout << "constructor of Singleton" << endl;
    }

private:
    static Singleton *singleton;
};