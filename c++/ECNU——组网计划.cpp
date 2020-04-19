#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

typedef struct edge
{
    int b, e;
    int len;

} edge;

bool state_over(vector<int> state)
{
    for (int i = 0; i < state.size(); ++i)
    {
        if (state[i] == 0)
            return true;
    }
    return false;
}

bool is_ok(edge a, vector<int> state)
{
    if (!(state[a.b] & state[a.e]) && (state[a.b] | state[a.e]))
        return true;
    else
        return false;
}

int main()
{
    int n;

    while (cin >> n)
    {
        vector<vector<int>> nodes(n, vector<int>(2));
        vector<edge> edges;

        for (int i = 0; i < n; ++i)
        {
            cin >> nodes[i][0] >> nodes[i][1];
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int len = abs(nodes[i][0] - nodes[j][0]) + abs(nodes[i][1] - nodes[j][1]);
                edges.push_back(edge{i, j, len});
            }
        }
        vector<int> exist(n, 0);
        vector<int> record1;
        exist[0] = 1;

        while (state_over(exist))
        {
            int min = 999999;
            int index;
            for (int i = 0; i < edges.size(); ++i)
            {
                if (is_ok(edges[i], exist) && edges[i].len < min)
                {
                    min = edges[i].len;
                    index = i;
                }
            }
            exist[edges[index].b] = exist[edges[index].e] = 1;
            record1.push_back(index);
        }

        exist.clear();
        exist.resize(n);

        vector<int> record2;
        exist[0] = 1;
        while (state_over(exist))
        {
            int min = 999999;
            int index;
            for (int i = edges.size() - 1; i >= 0; --i)
            {
                if (is_ok(edges[i], exist) && edges[i].len < min)
                {
                    min = edges[i].len;
                    index = i;
                }
            }
            exist[edges[index].b] = exist[edges[index].e] = 1;
            record2.push_back(index);
        }

        int sum = 0;
        string flag = "No";
        sort(record1.begin(), record1.end());
        sort(record2.begin(), record2.end());
        for (int i = 0; i < record1.size(); ++i)
        {
            if (record1[i] != record2[i])
                flag = "Yes";
            sum += edges[record1[i]].len;
        }
        cout << sum << endl;
        cout << flag << endl;
    }

    return 0;
}