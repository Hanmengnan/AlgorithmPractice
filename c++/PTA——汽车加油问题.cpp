#include <iostream>
#include <vector>
using namespace std;

int max_num = 9999;
int n, k;
int *dis;

void drive(int exist_gas, int aim_station, int num)
{
    if (aim_station - 1 == k + 1)
    {
        if (num < max_num)
            max_num = num;
        return;
    }
    if (exist_gas < dis[aim_station] || num >= max_num)
        return;
    drive(exist_gas - dis[aim_station], aim_station + 1, num);
    drive(exist_gas, aim_station + 1, num + 1);
}

int main()
{

    cin >> n >> k;
    dis = new int[k + 2]();
    for (int i = 1; i <= k + 1; ++i)
    {
        cin >> dis[i];
    }
    drive(n, 1, 0);
    if (max_num != 9999)
        cout << max_num;
    else
        cout << "No Solution!";
    return 0;
}