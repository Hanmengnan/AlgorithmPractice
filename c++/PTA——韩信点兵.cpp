#include <iostream>

using namespace std;

int main()
{
    int a, b, c;

    cin >> a >> b >> c;
    for (int i = 0; 7 * i + c < 105; ++i)
    {
        if ((7 * i + c) % 3 == a && (7 * i + c) % 5 == b)
        {
            cout << (7 * i + c) << endl;
            break;
        }
    }
    return 0;
}