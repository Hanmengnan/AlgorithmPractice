#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int n, t;

    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        nums[i] = t;
    }

    vector<int> sum(n);
    int r = sum[0] = nums[0];
    for (int i = 1; i < n; ++i)
    {
        sum[i] = max(sum[i - 1] + nums[i], nums[i]);
        if (sum[i] > r)
            r = sum[i];
    }

    if (r > 0)
        cout << r;
    else
        cout << 0;

    return 0;
}