#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int graph[101][101];
    int condition[101][101][10];
    int c, n;
    cin >> c;

    for (int k = 0; k < c; ++k)
    {
        cin >> n;
        memset(graph, 0, sizeof(graph));
        memset(condition, 0, sizeof(condition));

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                cin >> graph[i][j];
            }
        }
        for (int j = 1; j <= n; ++j)
        {
            condition[n][j][graph[n][j] % 10] = 1;
        }

        for (int i = n - 1; i >= 1; --i)
        {
            for (int j = 1; j <= i; ++j)
            {
                for (int k = 0; k <= 9; ++k)
                {
                    if (condition[i + 1][j][k] || condition[i + 1][j + 1][k])
                    {
                        condition[i][j][(k * graph[i][j]) % 10] = 1;
                    }
                }
            }
        }
        for (int k = 9; k >= 0; --k)
        {
            if (condition[1][1][k])
            {
                cout << k << endl;
                break;
            }
        }
    }
    return 0;
}