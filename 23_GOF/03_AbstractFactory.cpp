#include <iostream>

using namespace std;

enum PRODUCT_TYPE
{
    PRODUCTA = 0,
    PRODUCTB = 1,
};

class Product
{
public:
    virtual void show() = 0;
};

class ProductA : public Product
{
public:
    void show()
    {
        cout << "this is ProductA" << endl;
    }
};

class ProductB : public Product
{
public:
    void show()
    {
        cout << "this is ProductB" << endl;
    }
};

class Factory
{
public:
    virtual Product *ProduceProductA() = 0;
    virtual Product *ProduceProductB() = 0;
};

class Factory1 : public Factory
{
public:
    Product* ProduceProductA()
    {
        cout << "this is factory 1" << endl;
        return new ProductA;
    }

    Product* ProduceProductB()
    {
        cout << "this is factory 1" << endl;
        return new ProductB;
    }
};

class Factory2 : public Factory
{
public:
    Product* ProduceProductA()
    {
        cout << "this is factory 2" << endl;
        return new ProductA;
    }

    Product* ProduceProductB()
    {
        cout << "this is factory 2" << endl;
        return new ProductB;
    }
};

int main()
{
    Factory1 factory1;
    Factory2 factory2;

    Product* p1 = factory1.ProduceProductA();
    p1->show();

    Product* p2 = factory1.ProduceProductB();
    p2->show();

    Product* p3 = factory2.ProduceProductA();
    p3->show();

    Product* p4 = factory2.ProduceProductB();
    p4->show();

    delete p1;
    delete p2;
    delete p3;
    delete p4;

    return 0;
}