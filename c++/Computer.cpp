#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n;
    while (cin >> n)
    {
        int a, b;
        vector<vector<int>> graph(n + 1, vector<int>(n + 1, 999999));
        vector<int> dis(n + 1, 999999);
        for (int i = 2; i <= n; ++i)
        {
            cin >> a >> b;
            graph[i][a] = graph[a][i] = b;
        }

        for (int k = 1; k < n + 1; ++k)
        {
            for (int i = 1; i < n + 1; ++i)
            {
                for (int j = 1; j < n + 1; ++j)
                {
                    if (graph[i][k] != 999999 && graph[k][j] != 999999)
                    {
                        if (graph[i][j] > graph[i][k] + graph[k][j])
                        {
                            graph[i][j] = graph[i][k] + graph[k][j];
                        }
                    }
                }
            }
        }
        for (int k = 1; k < n + 1; ++k)
        {
            int max = 0;
            for (int i = 1; i < n + 1; ++i)
            {
                if (graph[k][i] != 999999 && max < graph[k][i])
                    max = graph[k][i];
            }
            cout << max << endl;
        }
    }
    return 0;
}