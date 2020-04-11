#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 99999));
    vector<int> dis(n + 1, 99999);
    int a, b, c;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        graph[a][b] = c;
    }
    for (int i = 2; i <= n; ++i)
    {
        dis[i] = graph[1][i];
    }

    for (int i = 2; i <= n; ++i)
    {
        if (dis[i] != 99999)
        {
            for (int j = 2; j <= n; ++j)
            {
                if (graph[i][j] != 99999 && dis[j] > dis[i] + graph[i][j])
                    dis[j] = dis[i] + graph[i][j];
            }
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        cout << dis[i] << endl;
    }

    return 0;
}