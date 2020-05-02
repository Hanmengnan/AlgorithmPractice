#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef struct goods
{
    int price;
    int cost;
} goods;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n, m;
        cin >> n >> m;

        vector<goods> goods_list(n + 1);
        vector<vector<int>> condition(n + 1, vector<int>(m + 1, 0));

        for (int j = 1; j <= n; ++j)
        {
            cin >> goods_list[j].cost >> goods_list[j].price;
        }
        for (int j = 1; j <= n; ++j)
        {
            for (int k = 1; k <= m; ++k)
            {
                if (k >= goods_list[j].cost)
                {
                    condition[j][k] = max(condition[j - 1][k], condition[j - 1][k - goods_list[j].cost] + goods_list[j].price);
                }
                else
                    condition[j][k] = condition[j - 1][k];
            }
        }
        cout << condition[n][m] << endl;
    }
    return 0;
}