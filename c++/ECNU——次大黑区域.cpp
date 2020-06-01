#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include<cstring>

#include <algorithm>

using namespace std;

typedef struct node
{
    int i, j;
} node;

int n, m;

int steps[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int graph[101][101];
int visit[101][101];
set<int> areas;

bool over_border(int a, int b)
{
    if (a > n || a < 1 || b > m || b < 1)
        return true;
    return false;
}

int main()
{
    int t;
    cin >> t;
    for (int k = 0; k < t; ++k)
    {

        memset(graph, 0, sizeof(graph));
        memset(visit, 0, sizeof(visit));
        areas.clear();
        queue<node> node_queue;

        cin >> n >> m;

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

                if (graph[i][j] && !visit[i][j])
                {
                    node_queue.push(node{i, j});
                    visit[i][j] = 1;

                    int sum = 1;

                    while (!node_queue.empty())
                    {
                        node temp = node_queue.front();
                        node_queue.pop();

                        for (int p = 0; p < 4; ++p)
                        {
                            int a = temp.i + steps[p][0];
                            int b = temp.j + steps[p][1];
                            if (!over_border(a, b) && graph[a][b] == 1 && !visit[a][b])
                            {
                                node_queue.push(node{a, b});
                                visit[a][b] = 1;
                                sum++;
                            }
                        }
                    }
                    areas.insert(sum);
                }
            }
        }

        cout << "case #" << k << ":" << endl;
        if (areas.size() == 1 || areas.size() == 0)
            cout << 0 << endl;
        else
        {
            set<int>::iterator i = areas.end();
            i--;
            i--;
            cout << *i << endl;
        }
    }
    return 0;
}