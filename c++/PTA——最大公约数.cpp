#include <iostream>
#define ll long long

using namespace std;

ll quickPow(ll x, ll y, ll p)
{
    ll res = 1;
    //x = x % p;
    while (y)
    {
        if (y & 1)
        {
            res = res * x;
        }
        x = x * x;
        y >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b)
{
    ll m = a > b ? a : b;
    ll n = a > b ? b : a;

    while (n)
    {
        ll temp;
        temp = m % n;
        m = n;
        n = temp;
    }
    return m;
}

int main()
{

    ll a, b, m, n, p;
    cin >> a >> b >> m >> n >> p;
    ll am = quickPow(a, m, p);
    ll bm = quickPow(b, m, p);
    ll rm = (am - bm) ;

    ll an = quickPow(a, n, p);
    ll bn = quickPow(b, n, p);
    ll rn = (an - bn) ;

    cout << gcd(rm, rn);
    return 0;
}
