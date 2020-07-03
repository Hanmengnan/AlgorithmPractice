#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, m;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> k >> m;
        if (m / (2.0) < (k - 100) * 0.99 && m / (2.0) > (k - 100) * 0.81)
        {
            cout << "You are wan mei!" << endl;
        }
        else if (m / (2.0) >= (k - 100) * 0.99)
        {
            cout << "You are tai pang le!" << endl;
        }
        else
        {
            cout << "You are tai shou le!" << endl;
        }
    }

    return 0;
}

