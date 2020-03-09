#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct edge
{
    int b;
    int e;
    int distance;
} edge;

bool my_cmp(edge a, edge b)
{
    return a.distance < b.distance;
}

int main()
{
    int m, n;
    cin >> n >> m;
    vector<edge> my_map(m);
    vector<bool> node_state(n + 1, false);
    vector<bool> edge_state(m, false);
    int a, b, distance;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> distance;
        edge temp;
        temp.b = a;
        temp.e = b;
        temp.distance = distance;
        my_map[i] = temp;
    }

    sort(my_map.begin(), my_map.end(), my_cmp);

    node_state[1] = true;
    int sum = 1;
    int sum_dis = 0;
    int flag = 0;
    while (sum != n)
    {
        flag = 0;
        for (int i = 0; i < my_map.size(); ++i)
        {
            if (edge_state[i] == false)
            {
                if ((node_state[my_map[i].b] | node_state[my_map[i].e]) && !(node_state[my_map[i].b] & node_state[my_map[i].e]))
                {
                    sum_dis += my_map[i].distance;
                    edge_state[i] = true;
                    node_state[my_map[i].b] = node_state[my_map[i].e] = true;
                    sum++;
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0)
            break;
    }
    if (sum != n)
        cout << "Impossible" << endl;
    else
        cout << sum_dis << endl;
    return 0;
}