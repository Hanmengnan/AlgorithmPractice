#define ll long long
#include <iostream>

using namespace std;
int main()
{
    ll a, b, p;

    cin >> a >> b >> p;

    ll sum = 0;
    a %= p;
    while (b)
    {
        if (b & 1)
        {
            sum += a;
            sum %= p;
        }
        b >>= 1;
        a <<= 1;
        a %= p;
    }
    cout << sum % p << endl;

    return 0;
}