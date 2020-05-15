#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    vector<int> nums;
    nums.push_back(1);

    do
    {
        n++;
        nums.push_back(nums[n - 1] * (n));

    } while (nums[n] * (n + 1) < 1000000);

    int k;
    while (cin >> k && k >= 0)
    {
        if (k == 0)
        {
            cout << "NO" << endl;
            continue;
        }
        for (int i = nums.size()-1; i >= 0; i--)
        {
            if (nums[i] <= k)
                k -= nums[i];
        }
        if (k == 0)
            cout << "YES" << endl;
		else cout << "NO" << endl;
    }

    return 0;
}