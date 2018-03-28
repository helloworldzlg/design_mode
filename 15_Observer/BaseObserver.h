#pragma once
#include <list>
#include <iostream>
#include <string>

using namespace std;

class Observer
{
public:
    Observer() {}
    virtual ~Observer() {}
    virtual void Update() {}
};

class Blog
{
public:
    Blog() {}
    virtual ~Blog() {}

    void Attach(Observer *observer)
    {
        m_observers.push_back(observer);
    }

    void Remove(Observer *observer)
    {
        m_observers.remove(observer);
    }

    void Notify()
    {
        list<Observer *>::iterator iter = m_observers.begin();
        for (; iter != m_observers.end(); ++iter)
            (*iter)->Update();
    }

    virtual void SetStatus(string s) {m_status = s;}
    virtual string GetStatus() {return m_status;}

private:
    list<Observer*> m_observers;

protected:
    string m_status;
};

