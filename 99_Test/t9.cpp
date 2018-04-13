#include <iostream>

using namespace std;

class Painter;
class Singer;
class Dancer;

class ArtistPerform
{
public:
    virtual void visitPainter(Painter& iPainter) = 0;
    virtual void visitSinger(Singer& iSinger) = 0;
    virtual void visitDancer(Dancer& iDancer) = 0;
};

class Artist
{
public:
    virtual void Accept(ArtistPerform& perform) = 0;
};

class Painter : public Artist
{
public:
    void paint()
    {
        cout << "I'm a Painter, I will paint a picture" << endl;
    }

    void Accept(ArtistPerform& perform)
    {
        perform.visitPainter(*this);
    }
};

class Singer : public Artist
{
public:
    void sing()
    {
        cout << "I'm a Singer, I will sing a song" << endl;
    }

    void Accept(ArtistPerform& perform)
    {
        perform.visitSinger(*this);
    }
};

class Dancer : public Artist
{
public:
    void dance()
    {
        cout << "I'm a Dancer, I will dance a dance" << endl;
    }

    void Accept(ArtistPerform& perform)
    {
        perform.visitDancer(*this);
    }
};

class Perform : public ArtistPerform
{
public:
    void visitPainter(Painter& iPainter)
    {
        iPainter.paint();
    };

    void visitSinger(Singer& iSinger)
    {
        iSinger.sing();
    }

    void visitDancer(Dancer& iDancer)
    {
        iDancer.dance();
    }
};

int main()
{
    Painter lily;
    Singer lucy;
    Dancer Tom;

    Perform perform;
    lily.Accept(perform);
    lucy.Accept(perform);
    Tom.Accept(perform);

    return 0;
}