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
    virtual Product *ProduceProduct() = 0;
};

class Factory1 : public Factory
{
public:
    Product* ProduceProduct()
    {
        return new ProductA;
    }
};

class Factory2 : public Factory
{
public:
    Product* ProduceProduct()
    {
        return new ProductB;
    }
};

int main()
{
    Factory1 factory1;
    Factory2 factory2;

    Product* p1 = factory1.ProduceProduct();
    Product* p2 = factory2.ProduceProduct();

    p1->show();
    p2->show();

    delete p1;
    delete p2;

    return 0;
}