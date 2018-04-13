#include <iostream>

using namespace std;

class Cock
{
public:
    virtual void crow()
    {
        cout << "this is Cock crow" << endl;
    }
};

class GeniusPerson
{
public:
    void skills()
    {
        cout << "this is GeniusPerson skills" << endl;
    }
};

class DoorKeeper
{
public:
    void OpenDoor(Cock& iChicken)
    {
        iChicken.crow();
    }
};

class ChickenAdapter : public Cock
{
public:
    ChickenAdapter(GeniusPerson& iGeniusPerson) : m_geniusPerson(iGeniusPerson)
    {}

    void crow()
    {
        m_geniusPerson.skills();
    }
private:
    GeniusPerson& m_geniusPerson;
};

int main()
{
    GeniusPerson mcj;
    ChickenAdapter chickenAdapter(mcj);

    DoorKeeper xa;
    xa.OpenDoor(chickenAdapter);
}