#include <iostream>

using namespace std;

int main()
{
    int c, n, m;
    cin >> c;
    while (c--)
    {

        cin >> n >> m;

        if (n % (m + 1))
            cout << "first" << endl;
        else
            cout << "second" << endl;
    }
    return 0;
}