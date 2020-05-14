#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int board[9][9];
int location[9];
int state[9];

int dfs(int n, int i)
{
    if (i == n + 1)
    {
        return 1;
    }
    int sum = 0;
    for (int k = 1; k <= n; ++k)
    {
        if (state[k] == 0)
        {
            int f = 0;
            for (int p = 1; p < i; ++p)
            {
                if (location[i - p] == k - p)
                    f = 1;
                else if (location[i - p] == k + p)
                    f = 1;
            }
            if (f == 0)
            {
                location[i] = k;
                state[k] = 1;

                int w = dfs(n, i + 1);
                sum += w;

                location[i] = 0;
                state[k] = 0;
            }
        }
    }

    return sum;
}

int main()
{
    int k;
    cin >> k;

    while (k--)
    {
        int n;
        cin >> n;

        memset(board, 0, sizeof(board));
        memset(location, 0, sizeof(location));
        memset(state, 0, sizeof(state));

        cout << dfs(n, 1) << endl;
    }
     return 0;
}