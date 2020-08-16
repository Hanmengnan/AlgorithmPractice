#include <iostream>
#include <vector>

using namespace std;

vector<int> num, vis, container;

int n, m;
int sum;

void printNum()
{
    if (sum > m)
        return;
    if (container.size() == n)
    {
        sum++;
        if (sum == m)
        {
            for (int i = 0; i < n; ++i)
            {
                if (i == 0)
                    cout << container[i];
                else
                    cout << " " << container[i];
            }
            cout << endl;
            return;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i] == 0)
        {
            container.push_back(i);
            vis[i] = 1;
            printNum();
            vis[i] = 0;
            container.pop_back();
            if (sum > m)
                return;
        }
    }
}

void init(int n)
{
    for (int i = 0; i < n; ++i)
    {
        num[i] = i + 1;
        vis[i] = 0;
    }
}

int main()
{

    while (cin >> n >> m)
    {
        num.clear();
        vis.clear();
        container.clear();

        vis.resize(n + 1);
        num.resize(n);
        sum = 0;
        init(n);
        printNum();
    }
    return 0;
}