#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> social(n + 1, vector<int>(n + 1, 0));

    int a, b;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        social[a][b] = social[b][a] = 1;
    }

    for (int i = 1; i <= n; ++i)
    {
        vector<int> state(n + 1, -1);
        queue<int> people;
        state[i] = 0;
        people.push(i);

        while (!people.empty())
        {
            int node = people.front();
            people.pop();
            for (int j = 1; j <= n; ++j)
            {
                if (state[j] < 0 && social[node][j] == 1)
                {
                    people.push(j);
                    state[j] = state[node] + 1;
                }
            }
        }
        int sum = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (state[j] >= 0 && state[j] <= 6)
            {
                sum++;
            }
        }
        printf("%d: %.2f%%\n",i, double(sum) / (n) * 100);
    }

    return 0;
}