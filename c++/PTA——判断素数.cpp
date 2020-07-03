#include <iostream>
#include <cmath>

#define ll long long

using namespace std;

int func(ll n)
{
    if (n == 2 || n == 3)
    {
        return 1;
    }
    else if (n == 1 || n == 4)
    {
        return 0;
    }
    for (ll i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int n;
    ll num;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        if (func(num))
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }

    return 0;
}