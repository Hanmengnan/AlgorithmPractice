#define INF 0x3f3f3f3f
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct edge
{
    int end;
    int len;
} edge;

int main()
{
    int T, R, P, S;
    cin >> T >> R >> P >> S;

    vector<vector<edge>> graph(T + 1);

    vector<int> dis(T + 1, INF);
    vector<int> state(T + 1, 0);

    deque<int> node_queue;

    int start, end, len;

    for (int i = 0; i < R; ++i)
    {
        cin >> start >> end >> len;
        graph[start].push_back(edge{end, len});
        graph[end].push_back(edge{start, len});
    }
    for (int i = 0; i < P; ++i)
    {
        cin >> start >> end >> len;
        graph[start].push_back(edge{end, len});
    }

    dis[S] = 0;
    state[S] = 1;
    node_queue.push_front(S);

    while (!node_queue.empty())
    {
        int node = node_queue.front();
        node_queue.pop_front();

        for (int i = 0; i < graph[node].size(); i++)
        {
            if (dis[graph[node][i].end] > dis[node] + graph[node][i].len)
            {
                dis[graph[node][i].end] = dis[node] + graph[node][i].len;
                if (state[graph[node][i].end] == 0)
                {
                    if (!node_queue.empty())
                    {
                        if (dis[graph[node][i].end] <= dis[node_queue.front()])
                            node_queue.push_front(graph[node][i].end);
                        else
                            node_queue.push_back(graph[node][i].end);
                    }
                    else
                        node_queue.push_front(graph[node][i].end);

                    state[graph[node][i].end] = 1;
                }
            }
        }
        state[node] = 0;
    }
    for (int i = 1; i <= T; ++i)
    {
        if (dis[i] >= INF)
            cout << "NO PATH" << endl;
        else
            cout << dis[i] << endl;
    }
    return 0;
}