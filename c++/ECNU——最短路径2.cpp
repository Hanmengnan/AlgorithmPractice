/*差一个点没过*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 99999

typedef struct edge
{
    int a, b;
} strcut;

int main()
{
    int n, m, a, b, c;

    cin >> n >> m;

    vector<vector<edge>> graph(n + 1);
    vector<int> dis(n + 1, INF), visit(n + 1, 0), num(n + 1, 0);

    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        graph[a].push_back(edge{b, c});
    }

    queue<int> node_q;
    node_q.push(1);
    dis[1] = 0;
    num[1] = 1;
    while (!node_q.empty())
    {
        int node = node_q.front();
        node_q.pop();
        visit[node] = 0;

        for (int i = 0; i < graph[node].size(); ++i)
        {
            edge t = graph[node][i];
            if (dis[t.a] > dis[node] + t.b)
            {
                num[t.a] = num[node];
                dis[t.a] = dis[node] + t.b;

                if (visit[t.a] == 0)
                {
                    node_q.push(t.a);
                    visit[t.a] = 1;
                }
            }
            else if (dis[t.a] == dis[node] + t.b)
            {
                num[t.a] += num[node];
            }
        }
    }
    if (dis[n] == INF)
    {
        cout << -1 << " " << 0;
    }
    else
    {
        cout << dis[n] << " " << num[n];
    }
    return 0;
}