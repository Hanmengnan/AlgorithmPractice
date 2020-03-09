#include <iostream>
#include <vector>

using namespace std;

int n, m, s;
int **my_map;
int *state;

void dfs(int now_node)
{
    if (m == n + 1)
    {
        return;
    }
    if (m != 1)
        cout << " ";
    cout << now_node;

    for (int i = 1; i <= n; ++i)
    {
        if (!state[i] && my_map[now_node][i])
        {
            m++;
            state[i] = 1;

            dfs(i);
            cout << " " << now_node;
        }
    }
    return;
}

int main()
{

    cin >> n >> m >> s;

    my_map = new int *[n + 1];
    state = new int[n + 1]();

    for (int i = 0; i <= n; ++i)
    {
        my_map[i] = new int[n + 1]();
    }

    int a, b;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        my_map[a][b] = my_map[b][a] = 1;
    }

    m = 1;
    state[s] = 1;

    dfs(s);

    if (m < n)
        cout << " " << 0;
    return 0;
}