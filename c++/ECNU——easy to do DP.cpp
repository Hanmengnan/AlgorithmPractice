#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int condition[22][1000020];
int quality[22];

int main()
{
    int n;

    while (cin >> n)
    {
        memset(condition, 0, sizeof(condition));
        memset(quality, 0, sizeof(quality));
        int count = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> quality[i];
            count += quality[i];
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= count / 2; ++j)
            {
                if (j >= quality[i])
                {
                    condition[i][j] = max(quality[i] + condition[i - 1][j - quality[i]], condition[i - 1][j]);
                }
                else
                {
                    condition[i][j] = condition[i - 1][j];
                }
            }
        }
        cout << count - condition[n][count / 2] * 2 << endl;
    }
    return 0;
}