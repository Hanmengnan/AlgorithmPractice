#define ll long long
#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef struct num
{
    ll a, b;
} num;

int cal_max(int a, int b)
{
    int m, n;
    m = a > b ? a : b;
    n = a > b ? b : a;
    while (n)
    {
        int t = n;
        n = m % n;
        m = t;
    }
    return m;
}
int main()
{
    int t, m, n;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cout << "case #" << i << ":" << endl;
        cin >> m >> n;
        if (n == 0)
        {
            cout << 1 << endl;
            continue;
        }
        else
        {
            vector<num> res(n);
            res[0].a = m;
            res[0].b = 1;
            for (int i = 1; i < n; ++i)
            {
                res[i].a = res[i - 1].a * (m - i);
                res[i].b = res[i - 1].b * (i + 1);
                int div = cal_max(res[i].a, res[i].b);
                res[i].a = res[i].a / div;
                res[i].b = res[i].b / div;
            }
            cout << res[n - 1].a / res[n - 1].b << endl;
        }
    }
    return 0;
}