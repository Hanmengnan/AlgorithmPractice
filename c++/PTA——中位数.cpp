#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main()
{

    ll n, k;
    while (cin >> n >> k)
    {
        vector<ll> a(n);
        vector<ll> lack(n);
        for (ll i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll mid = (n) / 2;

        for (ll i = mid; i + 1 < n; ++i)
        {
            lack[i + 1] = a[i + 1] - a[i];
        }

        ll w = 1;
        ll ans = a[mid];
        while (k > 0)
        {
            if ((k - lack[w + mid] * w) >= 0 && (w + mid) < n)
            {
                ans = a[w + mid];
                k -= lack[w + mid] * w;
                w++;
            }
            else
            {
                ans += k / w;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
