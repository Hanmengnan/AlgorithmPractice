#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maze[12][12] = {
    {0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1},
    {0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1},
    {0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
    {0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0}};

int state[12][12] = {0};
int step[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}};
int bx, by, ex, ey;
int mindis = 10000;

void explore(int x, int y, int dis)
{
    if (x == ex && y == ey)
    {
        if (mindis > dis)
            mindis = dis;
        return;
    }
	if (dis > mindis) return;
    for (int i = 0; i < 4; ++i)
    {
        int next_x = x + step[i][0];
        int next_y = y + step[i][1];
        if ((next_x > 11) || (next_y > 11) || (next_x < 0) || (next_y < 0))
            continue;
        if ((state[next_x][next_y] == 0) && (maze[next_x][next_y] == 0))
        {

            state[next_x][next_y] = 1;
            explore(next_x, next_y, dis + 1);
            state[next_x][next_y] = 0;
        }
    }
    return;
}

int main()
{
    cin >> bx >> by >> ex >> ey;

    state[bx][by] = 1;

    explore(bx, by, 0);
    cout << mindis;

    return 0;
}