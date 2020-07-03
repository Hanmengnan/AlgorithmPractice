#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n;
    while (n--)
    {
        cin >> m;
        if (m % 2 == 0)
        {
            cout << m / 4 << " " << m / 2 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }

    return 0;
}