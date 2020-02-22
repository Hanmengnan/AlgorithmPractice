#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int m, n;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        ios::sync_with_stdio(false);
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    for (int i = 0; i < m; ++i)
    {
        int aim;
        ios::sync_with_stdio(false);
        cin >> aim;
        if (i != 0)
            cout << " ";
        cout << find(nums.begin(), nums.end(), aim) - nums.begin();
    }
    return 0;
}