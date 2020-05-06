#include <iostream>
#include <cstring>
#include<cmath>

using namespace std;

int num[32];
int main()
{
    int n, m;

    while (cin >> n >> m)
    {
        if (n == -1 && m == -1)
            return 0;
        memset(num, 0, sizeof(num));
        num[m] = 1;
        for (int i = m + 1; i <= n; ++i)
        {
            num[i] = num[i - 1] * 2 + pow(2, (i - m - 1)) - num[i - m - 1];
        }
        cout << num[n] << endl;
    }
}
