#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int m;
        cin >> m;
        vector<vector<int>> tower(m, vector<int>(m));
        vector<vector<int>> dis(m, vector<int>(m, 0));
        for (int j = 0; j < m; ++j)
        {
            for (int l = 0; l <= j; ++l)
            {
                cin >> tower[j][l];
            }
        }
        dis[0][0] = tower[0][0];
        for (int j = 1; j < m; ++j)
        {
            for (int l = 0; l <= j; ++l)
            {
                if (l == 0)
                    dis[j][l] = dis[j - 1][l] + tower[j][l];
                else if (l == j)
                    dis[j][l] = dis[j - 1][l - 1] + tower[j][l];
                else
                    dis[j][l] = min((dis[j - 1][l - 1] + tower[j][l]), (dis[j - 1][l] + tower[j][l]));
            }
        }
        int min = 999999;
        for (int j = 0; j < m; ++j)
        {
            if (dis[m - 1][j] < min)
                min = dis[m - 1][j];
        }
        cout << min << endl;
    }
    return 0;
}