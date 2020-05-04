#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int c, n;
    cin >> c;
    for (int k = 0; k < c; ++k)
    {
        cin >> n;
        vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> sum_1(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> sum_2(n + 1, vector<int>(n + 1, 0));
        vector<int> max_1(n + 1, 0);
        vector<int> max_2(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                cin >> graph[i][j];
            }
        }
        sum_1[1][1] = graph[1][1];

        int temp = -1;
        for (int j = 1; j <= n; ++j)
        {
            sum_2[n][j] = graph[n][j];
            temp = temp > sum_2[n][j] ? temp : sum_2[n][j];
        }
        max_2[n] = temp;

        for (int i = 2; i <= n; ++i)
        {
            int temp = -1;
            for (int j = 1; j <= i; ++j)
            {
                if (j == 1)
                    sum_1[i][j] = (sum_1[i - 1][j] + graph[i][j]);
                else if (j == i)
                    sum_1[i][j] = (sum_1[i - 1][j - 1] + graph[i][j]);
                else
                {
                    sum_1[i][j] = max(sum_1[i - 1][j - 1], sum_1[i - 1][j]) + graph[i][j];
                }
                if (sum_1[i][j] > temp)
                    temp = sum_1[i][j];
            }
            max_1[i] = temp;
        }

        for (int i = n - 1; i >= 1; --i)
        {
            int temp = -1;
            for (int j = 1; j <= i; ++j)
            {
                sum_2[i][j] = max(sum_2[i + 1][j], sum_2[i + 1][j + 1]) + graph[i][j];
                if (sum_2[i][j] > temp)
                    temp = sum_2[i][j];
            }
            max_2[i] = temp;
        }

        temp = -1;
        for (int i = 2; i <= n - 1; ++i)
        {
            int sum = max_1[i] + max_2[i + 1];
            temp = sum > temp ? sum : temp;
        }
        cout << temp << endl;
    }
    return 0;
}