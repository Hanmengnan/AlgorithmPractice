#define ll long long
#include <iostream>

using namespace std;

ll my_pow(ll a, ll b, ll c)
{
    ll res = 1;
    ll n = a;
    while (b)
    {
        if (b & 1)
        {
            res = (res * n) % c;
        }
        n = (n * n) % c;
        b = b >> 1;
    }
    return res;
}
int main()
{
    int a, b, c;
    while (cin >> a >> b >> c)
    {
        if (a == 0 && b == 0 && c == 0)
            break;
        cout << my_pow(a, b, c) << endl;
    }
    return 0;
}
