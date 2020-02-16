#include <iostream>
#include <vector>

using namespace std;

int min_num, n, k;
int *weather;

void num_of_change(int state, int change_num, int use_num, int date)
{
    if (date == n)
    {
        if (min_num > change_num)
            min_num = change_num;
        return;
    }
    if (state == 0)
    {
        if (weather[date] >= 0)
        {
            num_of_change(state, change_num, use_num, date + 1);
        }
        else
        {
            if (use_num == 0)
                return;
            else
            {
                num_of_change(!state, change_num + 1, use_num - 1, date + 1);
            }
        }
    }
    else
    {
        if (weather[date] >= 0)
        {
            if (use_num == 0)
                num_of_change(!state, change_num + 1, use_num, date + 1);
            else
            {
                num_of_change(!state, change_num + 1, use_num, date + 1);
                num_of_change(state, change_num, use_num - 1, date + 1);
            }
        }
        else
        {
            if (use_num == 0)
                return;
            else
            {
                num_of_change(state, change_num, use_num - 1, date + 1);
            }
        }
    }
    return;
}

int main()
{

    while (cin >> n >> k)
    {

        min_num = 9999999;
        weather = new int[n + 1]();

        for (int i = 0; i < n; ++i)
        {
            cin >> weather[i];
        }
        num_of_change(0, 0, k, 0);
		if (min_num == 9999999)
			cout << -1 << endl;
		else
		cout << min_num << endl;
    }
    return 0;
}