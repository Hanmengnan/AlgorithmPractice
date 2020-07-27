#include <iostream>
using namespace std;

int main()
{
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double k1 = (y2 - y1) * 1.0 / (x2 - x1);
    double k2 = (y3 - y1) * 1.0 / (x3 - x1);



    if (k1 == k2)
        cout << "linear";
    else
    {
        cout << "clockwise";
    }
    return 0;
}