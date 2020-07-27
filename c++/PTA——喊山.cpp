#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, k, a, b;
    cin >> n >> m >> k;

    int graph[10001][10001] = {0};
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        graph[a][b] = graph[b][a] = 1;
    }
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (i != j && graph[i][j] > graph[i][k] + graph[k][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    for (int i = 0; i < k; ++i)
    {
        cin >> a;

        int max = -1;
        int index = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (graph[a][j] != 99999 && max < graph[a][j])
            {
                index = j;
                max = graph[a][j];
            }
        }
        if (i)
            cout << endl;
        cout << index;
    }

    return 0;
}