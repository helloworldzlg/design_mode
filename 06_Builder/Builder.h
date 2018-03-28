#pragma once
#include <iostream>

using namespace std;

class Builder
{
public:
    virtual void BuildHead() {}
    virtual void BuildBody() {}
    virtual void BuildLeftArm() {}
    virtual void BuildRightArm() {}
    virtual void BuildLeftleg() {}
    virtual void BuildRightLeg() {}
};

class ThinBuilder : public Builder
{
public:
    void BuildHead()
    {
        cout << "ThinBuilder BuildHead" << endl;
    }

    void BuildBody()
    {
        cout << "ThinBuilder BuildBody" << endl;
    }

    void BuildLeftArm()
    {
        cout << "ThinBuilder BuildLeftArm" << endl;
    }

    void BuildRightArm()
    {
        cout << "ThinBuilder BuildRightArm" << endl;
    }

    void BuildLeftleg()
    {
        cout << "ThinBuilder BuildLeftleg" << endl;
    }

    void BuildRightLeg()
    {
        cout << "ThinBuilder BuildRightLeg" << endl;
    }
};

class FatBuilder : public Builder
{
public:
    void BuildHead()
    {
        cout << "FatBuilder BuildHead" << endl;
    }

    void BuildBody()
    {
        cout << "FatBuilder BuildBody" << endl;
    }

    void BuildLeftArm()
    {
        cout << "FatBuilder BuildLeftArm" << endl;
    }

    void BuildRightArm()
    {
        cout << "FatBuilder BuildRightArm" << endl;
    }

    void BuildLeftleg()
    {
        cout << "FatBuilder BuildLeftleg" << endl;
    }

    void BuildRightLeg()
    {
        cout << "FatBuilder BuildRightLeg" << endl;
    }
};

class Director
{
public:
    Director(Builder *builder)
    {
        m_pBuilder = builder;
    }

    void setBuilder(Builder *builder)
    {
        m_pBuilder = builder;
    }

    void Create()
    {
        m_pBuilder->BuildHead();
        m_pBuilder->BuildBody();
        m_pBuilder->BuildLeftArm();
        m_pBuilder->BuildRightArm();
        m_pBuilder->BuildLeftleg();
        m_pBuilder->BuildRightLeg();
    }

private:
    Builder *m_pBuilder;
};