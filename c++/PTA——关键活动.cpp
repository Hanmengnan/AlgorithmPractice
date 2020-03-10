#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int>> works;
vector<int> in_degree;
vector<int> out_degree;

vector<int> earliest;
vector<int> lastest;
int n, m;

typedef struct edge
{
    int b, e, dis;
} edge;

bool cmp(edge a, edge b)
{
    if (a.b == b.b)
    {
        return a.dis > b.dis;
    }
    return a.b < b.b;
}
bool exist_loop()
{
    int count = 0;
    stack<int> logical_sort_stack;
    for (int i = 1; i <= n; ++i)
    {
        if (in_degree[i] == 0)
        {
            logical_sort_stack.push(i);
        }
    }

    while (!logical_sort_stack.empty())
    {
        int node = logical_sort_stack.top();
        logical_sort_stack.pop();
        count++;
        for (int i = 1; i <= n; ++i)
        {
            if (works[node][i])
            {
                if ((--in_degree[i]) == 0)
                    logical_sort_stack.push(i);
                if (earliest[node] + works[node][i] > earliest[i])
                    earliest[i] = works[node][i] + earliest[node];
            }
        }
    }
    return (count < n);
}

void lastest_time(int max_time)
{
    vector<int> temp(n + 1, max_time);
    lastest.assign(temp.begin(), temp.end());
    stack<int> lastest_stack;
    for (int i = 1; i <= n; ++i)
    {
        if (!out_degree[i])
            lastest_stack.push(i);
    }
    while (!lastest_stack.empty())
    {
        int node = lastest_stack.top();
        lastest_stack.pop();
        for (int i = 1; i <= n; ++i)
        {
            if (works[i][node])
            {
                lastest[i] = min(lastest[i], lastest[node] - works[i][node]);
                if (!(--out_degree[i]))
                    lastest_stack.push(i);
            }
        }
    }
}
int main()
{

    cin >> n >> m;

    works.resize(n + 1, vector<int>(n + 1, 0));
    in_degree.resize(n + 1);
    out_degree.resize(n + 1);

    earliest.resize(n + 1);
    lastest.resize(n + 1);

    int pre, later, dis;
    for (int i = 0; i < m; ++i)
    {
        cin >> pre >> later >> dis;
        works[pre][later] = dis;
        in_degree[later]++;
        out_degree[pre]++;
    }
    if (exist_loop())
    {
        cout << 0 << endl;
    }
    else
    {

        int max_time = -1;
        for (int i = n; i >= 1; --i)
        {

            if (!out_degree[i])
            {
                max_time = max(max_time, earliest[i]);
            }
        }

        cout << max_time << endl;

        lastest_time(max_time);
        vector<edge> sort_edge;
        for (int i = 1; i <= n; i++)
        {
            if (lastest[i] == earliest[i])
                for (int j = 1; j <= n; ++j)
                {
                    if (works[i][j] && lastest[j] == earliest[j] && (lastest[j] - works[i][j] == earliest[i]))
                    {
                        edge temp;
                        temp.b = i;
                        temp.e = j;
                        temp.dis = works[i][j];
                        sort_edge.push_back(temp);
                    }
                }
        }
        sort(sort_edge.begin(), sort_edge.end(), cmp);
        for (int i = 0; i < sort_edge.size(); i++)
        {
            cout << sort_edge[i].b << "->" << sort_edge[i].e << endl;
        }
    }
    return 0;
}