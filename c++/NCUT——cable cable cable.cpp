#include <iostream>
#define ll long long

using namespace std;

int main()
{
    ll m, k;
    while (cin >> m >> k)
    {
        cout << (m - k) * k + k << endl;
    }
    return 0;
}