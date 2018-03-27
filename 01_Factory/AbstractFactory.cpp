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

class MultiCore
{
public:
	virtual void show() = 0;
};

class MultiCoreA : public MultiCore
{
public:
	void show()
	{
		cout << "MultiCoreA" << endl;
	}
};

class MultiCoreB : public MultiCore
{
public:
	void show()
	{
		cout << "MultiCoreB" << endl;
	}
};

class Factory
{
public:
	virtual SingleCore *CreateSingleCore() = 0;
	virtual MultiCore *CreateMultiCore() = 0;
};

class FactoryA : public Factory
{
public:
	SingleCore *CreateSingleCore()
	{
		return new SingleCoreA;
	}

	MultiCore *CreateMultiCore()
	{
		return new MultiCoreA;
	}
};

class FactoryB : public Factory
{
public:
	SingleCore *CreateSingleCore()
	{
		return new SingleCoreB;
	}

	MultiCore *CreateMultiCore()
	{
		return new MultiCoreB;
	}
};

int main()
{
	FactoryA fa;
	FactoryB fb;

	SingleCore *p1 = fa.CreateSingleCore();
	SingleCore *p2 = fb.CreateSingleCore();

	MultiCore *p3 = fa.CreateMultiCore();
	MultiCore *p4 = fb.CreateMultiCore();

	p1->show();
	p2->show();
	p3->show();
	p4->show();

	delete p1;
	delete p2;
	delete p3;
	delete p4;

	return 0;
}