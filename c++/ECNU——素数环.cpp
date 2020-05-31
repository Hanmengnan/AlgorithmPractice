#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
int sum = 0;

vector<vector<int>> condition(50);
vector<int> visit(19, 0);

bool prime(int m)
{
    for (int i = 2; i <= sqrt(m); ++i)
    {
        if (m % i == 0)
            return false;
    }
    return true;
}

void dfs(int m)
{
    visit[m] = 1;
    condition[sum].push_back(m);

    for (int i = 2; i <= n; ++i)
    {
        if (!visit[i] && prime(m + i))
        {
            dfs(i);
        }
    }

    if (condition[sum].size() == n)
    {
        if (prime(1 + condition[sum][n - 1]))
        {
            for (int i = 0; i < n; ++i)
            {
                cout << condition[sum][i] << " ";
            }
            cout << endl;
        }
    }

    condition[sum].pop_back();
    visit[m] = 0;
}

int main()
{
    cin >> n;
    dfs(1);

    return 0;
}