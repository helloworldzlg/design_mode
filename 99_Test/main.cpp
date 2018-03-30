#include <stdio.h>
#include <iostream>

using namespace std;

class A
{
public:
    A(int ma = 100)
    {
        a = ma;
        cout << "A con" << endl;
    }

    int a;
};

class B :  virtual public A
{
public:
    B():A(10)
    {
        cout << "B con" << endl;
    }
};

class C :  virtual public A
{
public:
    C():A(20)
    {
        cout << "C con" << endl;
    }
};

class D : public B, public C
{
public:
    D()
    {
        cout << "D con" << endl;
    }
};


int main()
{
    D dt;
    printf("%d\n", sizeof(D));
    printf("%d\n", dt.a);
    return 0;\
}