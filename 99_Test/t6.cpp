#include <iostream>
#include <string>

using namespace std;

class Theme
{
public:
    virtual void setAttribute() = 0;
    virtual void getAttribute() = 0;
private:
    string color;
};

class DarkTheme : public Theme
{
public:
    void setAttribute()
    {
        cout << "this is DarkTheme setAttribute" << endl;
    }

    void getAttribute()
    {
        cout << "this is DarkTheme getAttribute" << endl;
    }
};

class LightTheme : public Theme
{
public:
    void setAttribute()
    {
        cout << "this is LightTheme setAttribute" << endl;
    }

    void getAttribute()
    {
        cout << "this is LightTheme getAttribute" << endl;
    }
};

class Blog
{
public:
    Blog(Theme& iTheme) : m_theme(iTheme)
    {}

    virtual void display() = 0;

    Theme& m_theme;
};

class BlogA : public Blog
{
public:
    BlogA(Theme& iTheme) : Blog(iTheme)
    {}

    void display()
    {
        cout << "this is BlogA with Attribute :" << endl;
        m_theme.getAttribute();
    }
};

class BlogB : public Blog
{
public:
    BlogB(Theme& iTheme) : Blog(iTheme)
    {}

    void display()
    {
        cout << "this is BlogB with Attribute :" << endl;
        m_theme.getAttribute();
    }
};

int main()
{
    DarkTheme darkTheme;

    BlogA ba(darkTheme);
    BlogB bb(darkTheme);

    ba.display();
    bb.display();

    return 0;
}