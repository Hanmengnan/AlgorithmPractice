#define INF -99999999
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m)
    {

        vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));

        int start, end, len;
        for (int i = 0; i < m; ++i)
        {
            cin >> start >> end >> len;
            graph[start][end] = len;
        }

        for (int k = 1; k <= n; ++k)
        {
            for (int i = 1; i <= n; ++i)
            {
                // if (i == k)
                //     continue;
                for (int j = 1; j <= n; ++j)
                {
                    // if (j == k)
                    //     continue;
                    if (graph[i][k] != INF && graph[k][j] != INF && graph[i][j] < graph[i][k] + graph[k][j])
                    {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
        int p, a, b;
        cin >> p;
        for (int i = 0; i < p; ++i)
        {
            cin >> a >> b;
            if (graph[a][b] != INF)
                cout << graph[a][b] << endl;
            else
                cout << -1 << endl;
        }
    }
    return 0;
}