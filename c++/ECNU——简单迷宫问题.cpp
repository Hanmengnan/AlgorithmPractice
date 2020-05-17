#include <iostream>
#include <cstring>

using namespace std;

char graph[201][201];
int visit[201][201];
int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int cost = 99999;
int bi, bj, ei, ej;
int n, m;

void dfs(int i, int j, int now_cost)
{
    if (i > n || i < 1 || j > m || j < 1)
        return;
    if (now_cost > cost)
        return;
    if (i == ei && j == ej)
    {
        if (now_cost < cost)
            cost = now_cost;
        return;
    }
    for (int k = 0; k < 4; ++k)
    {
        int new_i = i + moves[k][0];
        int new_j = j + moves[k][1];
        
        char c = graph[new_i][new_j];
        int state = visit[new_i][new_j];

        if (c != '#' && !state)
        {
            visit[new_i][new_j] = 1;
            if (c == 'X')
            {
                dfs(new_i, new_j, now_cost + 2);
            }
            else
            {
                dfs(new_i, new_j, now_cost + 1);
            }
            visit[new_i][new_j] = 0;
        }
    }
}
int main()
{

    while (cin >> n >> m)
    {
        memset(visit, 0, sizeof(visit));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                cin >> graph[i][j];
                if (graph[i][j] == 'S')
                {
                    bi = i;
                    bj = j;
                }
                else if (graph[i][j] == 'T')
                {
                    ei = i;
                    ej = j;
                }
            }
        }
        cost = 99999;
        visit[bi][bj] = 1;
        dfs(bi, bj, 0);
        if (cost == 99999)
            cout << "impossible" << endl;
        else
            cout << cost << endl;
    }

    return 0;
}