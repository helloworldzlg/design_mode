#include "Singleton.h"

int main()
{
    Singleton *st1 = Singleton::getInstance("SingletonA");
    Singleton *st2 = Singleton::getInstance("SingletonB");

    st1->show();
    st2->show();

    delete st1;
    //delete st2;

    return 0;
}