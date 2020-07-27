#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int gcd(int a, int b)
{
    int m = a > b ? a : b;
    int n = a > b ? b : a;

    while (n)
    {
        int temp;
        temp = m % n;
        m = n;
        n = temp;
    }
    return m;
}

int main()
{
    int n, t;
    cin >> n;
    vector<int> a, b;
    vector<int> left(n), right(n), pos(n);
    if (n <= 3)
    {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < n; ++i)
    {
        b.push_back(abs(a[i] - a[i - 1]));
    }

    left[1] = b[1];
    for (int i = 2; i < n; i++)
        left[i] = gcd(left[i - 1], b[i]);

    right[n - 1] = b[n - 1];
    for (int i = n - 2; i > 0; i--)
        right[i] = gcd(right[i + 1], b[i]);

    pos[1] = right[2];
    pos[n - 1] = left[n - 2];

    for (int i = 2; i < n - 1; i++) //去除i后的gcd
        pos[i] = gcd(left[i - 1], right[i + 1]);

    int maxx = pos[1];
    for (int i = 2; i < n; i++)
        if (pos[i] > maxx)
            maxx = pos[i];

    int ans = 0, ms = 0, ct = 0;
    for (int i = 1; i < n; i++)
    {
        if (b[i] % maxx != 0)
        {
            ++ct;
            continue;
        }
        ans += b[i] / maxx - 1;
        ms = max(ms, b[i] / maxx - 1);
    }
    if (!ct)
        ans -= ms;
    cout << ans << endl;

    return 0;
}

