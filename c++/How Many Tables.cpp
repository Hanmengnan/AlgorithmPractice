#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> father;

int getFather(int a)
{
    if (a == father[a])
        return a;
    else
    {
        father[a] = getFather(father[a]);
        return father[a];
    }
}

void unionNode(int a, int b)
{
    int fa = getFather(a);
    int fb = getFather(b);

    if (fa != fb)
    {
        father[getFather(a)] = fb;
    }

    return;
}

int main()
{
    int k;
    cin >> k;
    int n, m, a, b, count;
    while (k--)
    {
        father.clear();
        cin >> n >> m;
        father.resize(n + 1);

        for (int i = 1; i < 1 + n; ++i)
        {
            father[i] = i;
        }
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b;
            unionNode(a, b);
        }
        count = 0;
        for (int i = 1; i < 1 + n; ++i)
        {
            if (father[i] == i)
                count++;
        }
        cout << count << endl;
    }
    return 0;
}