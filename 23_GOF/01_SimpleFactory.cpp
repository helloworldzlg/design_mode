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
    static Product *ProduceProduct(PRODUCT_TYPE productType)
    {
        if (PRODUCTA == productType)
            return new ProductA;
        else if (PRODUCTB == productType)
            return new ProductB;
        else
            cout << "productType error" << endl;
    }
};

int main()
{
    Product* p1 = Factory::ProduceProduct(PRODUCTA);
    Product* p2 = Factory::ProduceProduct(PRODUCTB);

    p1->show();
    p2->show();

    delete p1;
    delete p2;

    return 0;
}