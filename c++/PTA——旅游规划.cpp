#include <iostream>
#include <vector>
#include <queue>

#define INF 99999

using namespace std;

typedef struct route
{
    int a, l, c;
} route;

int n, m, s, d;

int main()
{
    cin >> n >> m >> s >> d;

    vector<int> visit(n, 0), dis(n, INF), cost(n, INF);
    vector<vector<route>> graph(n);
    queue<int> node_q;

    int a, b, c, e;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c >> e;
        graph[a].push_back(route{b, c, e});
        graph[b].push_back(route{a, c, e});
    }
    node_q.push(s);
    dis[s] = 0;
    cost[s] = 0;

    while (!node_q.empty())
    {
        int node = node_q.front();
        node_q.pop();
        visit[node] = 0;

        for (int i = 0; i < graph[node].size(); ++i)
        {
            route t = graph[node][i];
            if (dis[t.a] > dis[node] + t.l)
            {
                dis[t.a] = dis[node] + t.l;
                cost[t.a] = cost[node] + t.c;

                if (visit[t.a] == 0)
                {
                    node_q.push(t.a);
                    visit[t.a] = 1;
                }
            }
            else if (dis[t.a] == dis[node] + t.l)
            {
                if (cost[t.a] > cost[node] + t.c)
                {
                    cost[t.a] = cost[node] + t.c;
                }
            }
        }
    }
    cout << dis[d] << " " << cost[d];

    return 0;
}