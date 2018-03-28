#pragma once
#include "BaseState.h"
#include <iostream>

using namespace std;

class EndState : public State
{
public:
    void End(War *war)
    {
        cout << "end of war" << endl;
    }
    void CurrentState(War *war)
    {
        End(war);
    }
};

class AnaphaseState : public State
{
public:
    void Anaphase(War *war)
    {
        if (war->getDays() < 30)
            cout << "Anaphase" << endl;
        else
        {
            war->setState(new EndState());
            war->getState();
        }
    }
    void CurrentState(War *war)
    {
        Anaphase(war);
    }
};

class MetaphaseState : public State
{
public:
    void Metaphase(War *war)
    {
        if (war->getDays() < 20)
            cout << "Metaphase" << endl;
        else
        {
            war->setState(new AnaphaseState());
            war->getState();
        }
    }
    void CurrentState(War *war)
    {
        Metaphase(war);
    }
};

class ProphaseState : public State
{
public:
    void Prophase(War* war)
    {
        if (war->getDays() < 10)
            cout << "Prophase" << endl;
        else
        {
            war->setState(new MetaphaseState());
            war->getState();
        }
    }
    void CurrentState(War *war)
    {
        Prophase(war);
    }
};

