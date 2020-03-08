#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> sticks;
vector<int> state;
int n, sum;

bool my_cmp(int a, int b)
{
	return a > b;
}

bool dfs(int rest_num, int test_length, int build_length, int index)
{
	if (rest_num == 0)
		return true;
	for (int i = index; i < n; ++i)
	{
		if (state[i] || (i && !state[i - 1] && (sticks[i] == sticks[i - 1])))
			continue;
		if (sticks[i] + build_length == test_length)
		{
			state[i] = 1;
			if (dfs(rest_num - 1, test_length, 0, 0))
				return true;
			state[i] = 0;
			return false;
		}
		if (sticks[i] + build_length < test_length)
		{
			state[i] = 1;
			if (dfs(rest_num, test_length, sticks[i] + build_length, i + 1))
				return true;
			state[i] = 0;
			if (!build_length)
				return false;
		}
	}
	return false;
}

int main()
{
	int flag;
	while (cin >> n)
	{
		if (n == 0)
			break;

		sticks.clear();
		state.clear();
		sticks.resize(n);
		state.resize(n);

		flag = sum = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> sticks[i];
			sum += sticks[i];
		}
		sort(sticks.begin(), sticks.end(), my_cmp);
		for (int l = sticks[0]; l <= sum / 2; ++l)
		{
			if (sum % l == 0)
			{
				int stick_num = sum / l;
				if (dfs(stick_num, l, 0, 0))
				{
					flag = 1;
					cout << l << endl;
					break;
				}
			}
		}
		if (flag == 0)
			cout << sum << endl;
	}
	return 0;
}