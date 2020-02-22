#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int figure[101][101];
int max_num[101][101];

int max_sum(int y, int x)
{
    if (max_num[y][x] != 0)
    {
        return max_num[y][x];
    }
    if (y == n - 1)
    {
        max_num[y][x] = figure[y][x];
    }
    else
    {
        int r1 = max_sum(y + 1, x);
        int r2 = max_sum(y + 1, x + 1);
        max_num[y][x] = max(r1, r2) + figure[y][x];
    }
    return max_num[y][x];
}

int main()
{

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            cin >> figure[i][j];
            max_num[i][j] = 0;
        }
    }

    int max = max_sum(0, 0);

    cout << max;
    return 0;
}