#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int m, n;

char graph[1001][81];
int visit[1001][81];
int steps[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int max_area = 0;

bool over_border(int a, int b)
{
    if (a > n || a < 1 || b > m || b < 1)
        return true;
    return false;
}

void dfs(int a, int b, int &area)
{
    visit[a][b] = 1;
    for (int i = 0; i < 4; ++i)
    {

        int new_a = a + steps[i][0];
        int new_b = b + steps[i][1];

        if (!over_border(new_a, new_b) && graph[new_a][new_b] == '*' && !visit[new_a][new_b])
        {
            area++;
            dfs(new_a, new_b, area);
        }
    }
}

int main()
{

    cin >> m >> n;

    memset(graph, '.', sizeof(graph));
    memset(visit, 0, sizeof(visit));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> graph[i][j];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (graph[i][j] == '*' && !visit[i][j])
            {
                int area = 1;
                dfs(i, j, area);
                if (area > max_area)
                    max_area = area;
            }
        }
    }
    cout << max_area;
    return 0;
}