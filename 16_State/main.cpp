#include "SpecificState.h"

int main()
{
    War *war = new War(new ProphaseState());

    for (int i = 1; i < 40; i += 5)
    {
        war->setDays(i);
        war->getState();
    }

    delete war;

    return 0;
}