#define _CRT_SECURE_NO_WARNINGS
#define INF 999999
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef struct edge
{
    int end;
    int dis;
} edge;
int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, INF));
    map<string, int> ip;
    string send, receive;
    int begin, end, len;
    int count = 0;
    for (int i = 0; i < m; ++i)
    {
        cin >> send >> receive;
        cin >> len;

        if (ip.find(send) == ip.end())
        {
            begin = count++;
            ip[send] = begin;
        }
        else
        {
            begin = ip[send];
        }
        if (ip.find(receive) == ip.end())
        {
            end = count++;
            ip[receive] = end;
        }
        else
        {
            end = ip[receive];
        }
        graph[begin][end] = graph[end][begin] = len;
    }
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (graph[i][k] != INF && graph[k][j] != INF && graph[i][j] > graph[i][k] + graph[k][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> send >> receive;
        if (ip.find(send) == ip.end() || ip.find(receive) == ip.end())
            cout << -1 << endl;
        else
        {
            begin = ip[send];
            end = ip[receive];
            if (graph[begin][end] != INF)
                cout << graph[begin][end] << endl;
            else
                cout << -1 << endl;
        }
    }
    return 0;
}