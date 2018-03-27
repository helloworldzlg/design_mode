#include <iostream>

using namespace std;

enum CTYPE
{
	COREA = 0,
	COREB = 1,
};

class SingleCore
{
public:
	virtual void show() = 0;
};

class SingleCoreA : public SingleCore
{
public:
	void show()
	{
		cout << "SingleCoreA" << endl;
	}
};

class SingleCoreB : public SingleCore
{
public:
	void show()
	{
		cout << "SingleCoreB" << endl;
	}
};

class Factory
{
public:
	virtual SingleCore *CreateSingleCore() = 0;
};

class FactoryA : public Factory
{
public:
	SingleCore *CreateSingleCore()
	{
		return new SingleCoreA;
	}
};

class FactoryB : public Factory
{
public:
	SingleCore *CreateSingleCore()
	{
		return new SingleCoreB;
	}
};

int main()
{
	FactoryA fa;
	FactoryB fb;

	SingleCore *p1 = fa.CreateSingleCore();
	SingleCore *p2 = fb.CreateSingleCore();

	p1->show();
	p2->show();

	delete p1;
	delete p2;

	return 0;
}