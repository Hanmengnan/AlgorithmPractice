#define INF 9999999
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct edge
{
    int end;
    int len;
    int fee;
} edge;
int main()
{

    int rl, rf;
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    vector<vector<edge>> graph(n);
    vector<int> dis(n, INF);
    vector<int> fees(n, INF);
    vector<int> state(n, 0);
    queue<int> node_queue;

    int start, end, len, fee;
    for (int i = 0; i < m; ++i)
    {
        cin >> start >> end >> len >> fee;
        graph[start]
            .push_back(edge{end, len, fee});
        graph[end]
            .push_back(edge{start, len, fee});
    }

    node_queue.push(s);
    state[s] = 1;
    dis[s] = 0;
    fees[s] = 0;

    int flag = 0;
    while (!node_queue.empty())
    {
        flag++;
        int node = node_queue.front();
        node_queue.pop();
        state[node] = 0;

        for (int i = 0; i < graph[node].size(); ++i)
        {

            if (dis[graph[node][i].end] > dis[node] + graph[node][i].len)
            {
                flag = 1;
                dis[graph[node][i].end] = dis[node] + graph[node][i].len;
                fees[graph[node][i].end] = fees[node] + graph[node][i].fee;
                if (!state[graph[node][i].end])
                {
                    node_queue.push(graph[node][i].end);
                    state[graph[node][i].end] = 1;
                }
            }
            else if (dis[graph[node][i].end] == dis[node] + graph[node][i].len)
            {

                if (fees[graph[node][i].end] > fees[node] + graph[node][i].fee)
                {
                    flag = 1;
                    fees[graph[node][i].end] = fees[node] + graph[node][i].fee;
                }
                if (!state[graph[node][i].end])
                {
                    node_queue.push(graph[node][i].end);
                    state[graph[node][i].end] = 1;
                }
            }
        }
        if (flag == n)
            break;
    }
    cout << dis[d] << " " << fees[d];
    return 0;
}
