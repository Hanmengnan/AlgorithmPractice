#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        cin >> nums[i];
    }
    int p, kl, xr, sum, result;
    for (int i = 0; i < m; ++i)
    {

        cin >> p >> kl >> xr;
        if (p == 1)
        {
            nums.insert(nums.begin() + kl + 1, xr);
        }
        else if (p == 2)
        {
            result = sum = nums[kl];

            for (int j = kl + 1; j <= xr; ++j)
            {
                sum = max(nums[j], sum + nums[j]);
                result = max(result, sum);
            }
            cout << result << endl;
        }
    }
    return 0;
}


