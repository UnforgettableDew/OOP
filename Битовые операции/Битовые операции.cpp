#include <iostream>
#include "EI.h"
using namespace std;

int main()
{
    int a, b, c;
    cout << "Enter numbers for checking on equality:\n";
    cin >> a >> b;

    if (Equality(a, b) == true)
        cout << a << " equal to " << b << endl;
    else
        cout << a << " not equal to " << b << endl;

    cout << "\nEnter the number for incrementing:\n";
    cin >> c;

    Increment(c);

    cout << "The incremented number: " << c;
    return 0;
}

