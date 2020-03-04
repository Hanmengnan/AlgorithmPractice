#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> result_nums;
    vector<int> nums;

    int n, m;
    int l, r, k;

    cin >> n;

    int temp_num;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp_num;
        nums.push_back(temp_num);
    }
    cin >> m;

    for (int i = 0; i < m; ++i)
    {
        result_nums.clear();

        cin >> l >> r >> k;
        result_nums.assign(nums.begin() + (l - 1), nums.begin() + r);
        sort(result_nums.begin(), result_nums.end());
        cout << result_nums[result_nums.size() - k] << endl;
    }

    return 0;
}