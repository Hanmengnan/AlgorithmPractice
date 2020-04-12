#define INF 99999
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> state(n + 1, 0);
    vector<int> dis(n + 1, INF);
    queue<int> node_queue;

    int start, end, len;
    for (int i = 0; i < m; ++i)
    {
        cin >> start >> end >> len;
        graph[start].push_back(end);
        graph[start].push_back(len);
    }

    state[1] = 1;
    dis[1] = 0;
    node_queue.push(1);

    while (!node_queue.empty())
    {
        int node = node_queue.front();
        node_queue.pop();
        state[node] = 0;

        for (int i = 0; i < graph[node].size(); i += 2)
        {
            if (dis[graph[node][i]] > dis[node] + graph[node][i + 1])
            {
                dis[graph[node][i]] = dis[node] + graph[node][i + 1];
                if (!state[graph[node][i]])
                {
                    node_queue.push(graph[node][i]);
                    state[graph[node][i]] = 1;
                }
            }
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        cout << dis[i] << endl;
    }
    return 0;
}