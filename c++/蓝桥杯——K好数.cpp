#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int digit[101][101];
int main()
{
    int k, l;
    while (cin >> k >> l)
    {
        if (l == 1)
        {
            cout << k - 1 << endl;
            continue;
        }
        memset(digit, 0, sizeof(digit));

        for (int i = 0; i < k; ++i)
        {
            digit[1][i] = 1;
        }

        for (int i = 2; i < l; ++i)
        {
            for (int j = 0; j < k; ++j)
            {
                int sum = 0;
                for (int r = 0; r < k; ++r)
                {
                    if (r == j + 1 || r == j - 1)
                    {
                        continue;
                    }
                    sum = (digit[i - 1][r] + sum) % 1000000007;
                }
                digit[i][j] = sum;
            }
        }
        int sum = 0;
        for (int i = 1; i < k; ++i)
        {
            int temp = 0;
            for (int j = 0; j < k; ++j)
            {
                if (j == i - 1 || j == i + 1)
                {
                    continue;
                }
                temp += digit[l - 1][j];
            }
            sum = (temp + sum) % 1000000007;
        }
        cout << sum << endl;
    }
    return 0;
}