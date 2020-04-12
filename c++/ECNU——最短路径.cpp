#define INF 9999999
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct edge
{
    int end;
    int len;
} edge;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> graph(n + 1);
    vector<int> state(n + 1, 0);
    vector<int> dis(n + 1, INF);
    deque<int> node_queue;

    int u, v, w;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        graph[u].push_back(edge{v, w});
    }
    state[1] = 1;
    dis[1] = 0;
    node_queue.push_back(1);

    while (!node_queue.empty())
    {
        int node = node_queue.front();
        node_queue.pop_front();
        state[node] = 0;
        for (int i = 0; i < graph[node].size(); ++i)
        {
            if (dis[graph[node][i].end] > dis[node] + graph[node][i].len)
            {
                dis[graph[node][i].end] = dis[node] + graph[node][i].len;
                if (state[graph[node][i].end] == 0)
                {
                    state[graph[node][i].end] = 1;
                    if (!node_queue.empty())
                    {
                        if (dis[graph[node][i].end] > dis[node_queue.front()])
                            node_queue.push_back(graph[node][i].end);
                        else
                            node_queue.push_front(graph[node][i].end);
                    }
                    else
                        node_queue.push_front(graph[node][i].end);
                }
            }
        }
    }
    if (dis[n] == INF)
        cout << -1;
    else
        cout << dis[n];
    return 0;
}