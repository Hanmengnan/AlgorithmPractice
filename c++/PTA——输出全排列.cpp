#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> flag(9, false);
vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
vector<int> container;

int n;

void dfs()
{
    if (container.size() == n)
    {
        for (int i = 0; i < n; ++i)
        {
            cout << container[i];
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            if (flag[i] == false)
            {
                container.push_back(nums[i]);
                flag[i] = true;
                dfs();
                flag[i] = false;
                container.pop_back();
            }
        }
    }
}

int main()
{
    cin >> n;
	dfs();
    return 0;
}