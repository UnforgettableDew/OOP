#include <iostream>
using namespace std;

void Increment(int& x)
{
    int i;
    for (i = 1; (x & i) != 0; i <<= 1)
    {
        x &= ~i;
    }
    x |= i;
} 

bool Equality(int x, int y)
{
    if ((x ^ y) == 0)
        return true;
    else
        return false;
}