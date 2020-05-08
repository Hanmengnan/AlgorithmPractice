#define ll long long
#define mod 1000000007
#include <iostream>
#include <cstring>

using namespace std;

//物品分布情况
int graph[51][51];

//横坐标、纵坐标、物品数量、最大价值
//数组的值表示取法有多少种
ll num[51][51][13][13];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    memset(graph, 0, sizeof(graph));
    memset(num, 0, sizeof(num));

    int max_price = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> graph[i][j];
            graph[i][j]++;
            max_price = max_price < graph[i][j] ? graph[i][j] : max_price;
        }
    }

    num[1][1][0][0] = 1;
    num[1][1][1][graph[1][1]] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            for (int l = 0; l <= k; ++l)
            {
                for (int m = 0; m <= max_price; ++m)
                {
                    if (i != 1)
                    {
                        num[i][j][l][m] += num[i - 1][j][l][m];
                        num[i][j][l][m] %= mod;
                        if (graph[i][j] > m)
                        {
                            num[i][j][l + 1][graph[i][j]] += num[i - 1][j][l][m];
                            num[i][j][l + 1][graph[i][j]] %= mod;
                        }
                    }
                    if (j != 1)
                    {
                        num[i][j][l][m] += num[i][j - 1][l][m];
                        num[i][j][l][m] %= mod;
                        if (graph[i][j] > m)
                        {
                            num[i][j][l + 1][graph[i][j]] += num[i][j - 1][l][m];
                            num[i][j][l + 1][graph[i][j]] %= mod;
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= max_price; i++)
    {
        ans = (ans + num[n][m][k][i]) % mod;
    }
    cout << ans << endl;
    return 0;
}