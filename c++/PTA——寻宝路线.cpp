#include <iostream>

#include <algorithm>
using namespace std;

int m, n;

int num = 0;

int maze[100][100] = {
    0,
};
int best[100][100] = {
    0,
};
int step[2][2] = {{0, -1}, {-1, 0}};

void explore(int x, int y, int worth)
{
    if (worth == maze[0][0])
    {
        num++;
        return;
    }
    for (int i = 0; i < 2; ++i)
    {
        int next_x = x + step[i][0];
        int next_y = y + step[i][1];

        if ((next_x < 0) || (next_y < 0))
            continue;
        if (worth-maze[x][y]==best[next_x][next_y])
        {
            explore(next_x, next_y, worth - maze[x][y]);
        }
    }
    return;
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> maze[i][j];
        }
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == 0 && j == 0)
                best[0][0] = maze[0][0];
            else if (i == 0)
            {
                best[i][j] = best[0][j - 1] + maze[i][j];
            }
            else if (j == 0)
            {
                best[i][j] = best[i - 1][0] + maze[i][j];
            }
            else
            {
                best[i][j] = max(best[i - 1][j], best[i][j - 1]) + maze[i][j];
            }
        }
	}
	/*cout << endl;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << best[i][j]<<" ";
		}
        cout<<endl;
	}*/
    explore(m - 1, n - 1, best[m - 1][n - 1]);
    cout << best[m - 1][n - 1] << " " << num;
    return 0;
}
