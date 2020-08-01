#include <iostream>
#include <vector>

using namespace std;

int n, m, a, b, sum;
vector<int> father(1001);
vector<int> graph(1001, 0);

int find(int x)
{
    if (x == father[x])
        return x;
    else
        return father[x] = find(father[x]);
}

void Union(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    father[x] = y;
    sum--;
}

int main()
{

    while (cin >> n)
    {

        if (n == 0)
            return 0;
        sum = n;
        cin >> m;

        for (int i = 1; i <= n; i++)
            father[i] = i;

        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b;
            graph[a]++;
            graph[b]++;
            Union(a, b);
        }

        if (sum == 1)
        {
            int flag = 1;
            for (int i = 1; i <= n; i++)
                if (graph[i] & 1)
                {
                    flag = 0;
                    break;
                }
            if (flag)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }

        else
            cout << 0 << endl;
    }
    return 0;
}