#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int matrix[501][501];
int n, m;

int cal_max(vector<int> array)
{
    vector<int> dp(m + 1);
    dp[1] = array[1];

    int max = dp[1];

    for (int i = 2; i <= m; ++i)
    {
        dp[i] = (dp[i - 1] + array[i]) > array[i] ? (dp[i - 1] + array[i]) : array[i];
        max = max > dp[i] ? max : dp[i];
    }
    return max;
}
int main()
{

    cin >> n >> m;

    memset(matrix, 0, sizeof(matrix));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> matrix[i][j];
        }
    }
    int max = -999999;
    for (int i = 1; i <= n; ++i)
    {
        vector<int> array(m + 1, 0);
        for (int j = i; j <= n; ++j)
        {
            for (int l = 1; l <= m; ++l)
            {
                array[l] += matrix[j][l];
            }
            int r = cal_max(array);
            max = r > max ? r : max;
        }
    }
    cout << max << endl;

    return 0;
}