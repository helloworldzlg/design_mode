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
	SingleCore *CreateSingleCore(enum CTYPE ctype)
	{
		if (COREA == ctype)
			return new SingleCoreA();
		else if (COREB == ctype)
			return new SingleCoreB();
		else
			return NULL;
	}
};

int main()
{
	Factory f;
	SingleCore *p1 = f.CreateSingleCore(COREA);
	SingleCore *p2 = f.CreateSingleCore(COREB);

	p1->show();
	p2->show();

	delete p1;
	delete p2;

	return 0;
}