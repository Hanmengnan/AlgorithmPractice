#include <iostream>
#include <vector>
#include <queue>
#include <set>

#define INF 99999
using namespace std;

int n, m, c1, c2;
int max_t = 0;

vector<vector<int>> graph(501, vector<int>(501, INF)), pre(501, vector<int>(501));
vector<int> dis(501, INF), num(501, 0), visit(501, 0), teams(501, 0);
queue<int> city_queue;

void cal(int p, int sum)
{
    if (p == c2)
    {
        if (max_t < sum)
            max_t = sum;
        return;
    }

    set<int> t(pre[p].begin(), pre[p].end());
    for (set<int>::iterator i = t.begin(); i != t.end(); ++i)
    {
        cal(*i, sum + teams[*i]);
    }
}

int main()
{
    cin >> n >> m >> c1 >> c2;

    for (int i = 0; i < n; ++i)
    {
        cin >> teams[i];
        graph[i][i] = 0;
    }

    int a, b, c;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        graph[a][b] = graph[b][a] = c;
    }

    dis[c2] = 0;
    num[c2] = 1;
    visit[c2] = 1;

    city_queue.push(c2);

    while (!city_queue.empty())
    {
        int c = city_queue.front();
        city_queue.pop();
        visit[c] = 0;

        for (int i = 0; i < n; ++i)
        {
            if (graph[c][i] != INF)
                if (dis[i] > dis[c] + graph[c][i])
                {
                    pre[i].clear();
                    pre[i].push_back(c);

                    dis[i] = dis[c] + graph[c][i];
                    num[i] = num[c];
                    if (!visit[i])
                    {
                        city_queue.push(i);
                        visit[i] = 1;
                    }
                }
                else if (dis[i] == dis[c] + graph[c][i])
                {
                    if (i != c)
                    {
                        pre[i].push_back(c);
                        num[i] += num[c];
                    }
                }
        }
    }

    cal(c1, teams[c1]);

    cout << num[c1] << " " << max_t;
    return 0;
}