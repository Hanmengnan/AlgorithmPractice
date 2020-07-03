#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define INF 0x3f3f3f3f

using namespace std;

typedef struct edge
{
    int b, e, l;
} edge;

vector<vector<edge>> graph;
int visit[5001], dis_b[5001], dis_e[5001];
vector<edge> edge_list;

int n, r;

void SFPA(int start, int *dis)
{
    memset(visit, 0, sizeof(visit));
    queue<int> node_queue;
    node_queue.push(start);
    dis[start] = 0;

    while (!node_queue.empty())
    {
        int node = node_queue.front();
        node_queue.pop();
        visit[node] = 0;

        for (int i = 0; i < graph[node].size(); ++i)
        {
            edge t = graph[node][i];
            if (dis[t.e] > dis[node] + t.l)
            {
                dis[t.e] = dis[node] + t.l;
                if (!visit[t.e])
                {
                    node_queue.push(t.e);
                    visit[t.e] = 1;
                }
            }
        }
    }
}

int main()
{
    int a, b, d;
    cin >> n >> r;

    memset(dis_b, INF, sizeof(dis_b));
    memset(dis_e, INF, sizeof(dis_e));

    graph.resize(n + 1);

    for (int i = 0; i < r; ++i)
    {
        cin >> a >> b >> d;
        graph[a].push_back(edge{a, b, d});
        graph[b].push_back(edge{b, a, d});
        
        edge_list.push_back(edge{b, a, d});
        edge_list.push_back(edge{a, b, d});
    }

    SFPA(1, dis_b);
    SFPA(n, dis_e);

    int min = INF;

    for (int i = 0; i < edge_list.size(); ++i)
    {
        edge t = edge_list[i];
        int len = dis_b[t.b] + dis_e[t.e] + t.l;
        if (len > dis_b[n] && len < min)
        {
            min = len;
        }
    }

    cout << min << endl;

    return 0;
}
