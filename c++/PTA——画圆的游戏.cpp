#include <iostream>
#include <math.h>
using namespace std;

int main()
{

    int x, y, r;
    while (cin >> x >> y >> r)
    {
        if (x < 2 * r || y < 2 * r)
            cout << "It is boring!" << endl;
        else
            cout << "It is so easy!" << endl;
    }
    return 0;
}