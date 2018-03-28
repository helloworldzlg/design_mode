#include "Builder.h"

int main()
{
    FatBuilder fb;
    Director director(&fb);
    director.Create();

    ThinBuilder tb;
    director.setBuilder(&tb);
    director.Create();

    return 0;
}