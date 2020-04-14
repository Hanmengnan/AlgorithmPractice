#define INF 999999
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;

// int main()
// {
//     int a, b;
//     cin >> n >> a >> b;

//     vector<vector<int>> elevator(n + 1, vector<int>(n + 1, INF));
//     int len, end;
//     for (int i = 1; i <= n; ++i)
//     {
//         cin >> len;
//         if (len + i <= n && len + i >= 1)
//             elevator[i][len + i] = 1;
//         if (i - len <= n && i - len >= 1)
//             elevator[i][i - len] = 1;
//     }

//     for (int k = 1; k <= n; ++k)
//         for (int i = 1; i <= n; ++i)
//             for (int j = 1; j <= n; ++j)
//             {
//                 if (elevator[i][k] != INF && elevator[k][j] != INF && elevator[i][j] > elevator[i][k] + elevator[k][j])
//                     elevator[i][j] = elevator[i][k] + elevator[k][j];
//             }
//     if (elevator[a][b] != INF)
//         cout << elevator[a][b];
//     else
//         cout << -1;
//     return 0;
// }

int main()
{

    int a, b;
    cin >> n >> a >> b;

    vector<int> elevator(n + 1);
    int len, end;
    for (int i = 1; i <= n; ++i)
    {
        cin >> elevator[len];
    }
    queue<int> node_queue;
    node_queue.push(a);

    int m = 0;
    while (!node_queue.empty())
    {
        int node = node_queue.front();
        if (node == b)
            break;
        node_queue.pop();

        if (node - elevator[node] > 0)
            node_queue.push(node - elevator[node]);
        if (node + elevator[node] < n + 1)
            node_queue.push(node + elevator[node]);
        m++;
    }
}