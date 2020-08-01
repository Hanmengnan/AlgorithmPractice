#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1));

    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cin >> graph[i][j];
            graph[j][i] = graph[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
        sort(graph[i].begin() + 1, graph[i].begin() + n + 1, cmp);

    int ans = 0;

    for (int i = 1; i <= n; i++)
        if (graph[i][2] > ans)
            ans = graph[i][2];
    cout << "1\n"
         << ans;
    return 0;
}