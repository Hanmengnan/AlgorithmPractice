#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        vector<vector<int>> condition(n + 1, vector<int>(m + 1, 0));
        vector<int> weight(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> weight[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (j >= weight[i])
                {
                    condition[i][j] = max(weight[i] + condition[i - 1][j - weight[i]], condition[i - 1][j]);
                }
                else
                    condition[i][j] = condition[i - 1][j];
            }
        }
        cout << m - condition[n][m] << endl;
    }
    return 0;
}