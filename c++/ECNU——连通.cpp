#include <iostream>
#include <vector>

using namespace std;

vector<int> boss;
int get_boss(int a)
{
    if (boss[a] == a)
        return a;
    else
    {
        boss[a] = get_boss(boss[a]);
        return boss[a];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    boss.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        boss[i] = i;
    }
    int u, v;
    int b_u, b_v;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        b_u = get_boss(u);
        b_v = get_boss(v);
        boss[b_v] = b_u;
    }
    int flag = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (get_boss(i) != boss[1])
            flag = 1;
    }

    if (flag)
        cout << "no" << endl;
    else
        cout << "yes" << endl;
    return 0;
}