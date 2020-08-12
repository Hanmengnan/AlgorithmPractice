#include <iostream>
#include <vector>

using namespace std;

typedef struct seq
{
    int x, y;
} seq;

int main()
{
    int n, t;
    cin >> n;

    vector<int> nums;
    vector<seq> dp(n);

	for (int i = 0; i < n; ++i)
	{
        cin >> t;
        nums.push_back(t);
    }

    int be = nums[0];
    dp[0] = seq{0, 0};
    for (int i = 1; i < n; ++i)
    {
        if (nums[i] > be)
        {
            dp[i] = seq{dp[i - 1].x, dp[i - 1].y + 1};
			
        }
        else
        {
            dp[i] = seq{i, i};
        }
		be = nums[i];
    }
    int maxl = 0, maxi = 0;
    for (int i = 0; i < n; ++i)
    {
        if (maxl < dp[i].y - dp[i].x)
        {
            maxl = dp[i].y - dp[i].x;
            maxi = i;
        }
    }
    for (int i = dp[maxi].x; i < dp[maxi].y; ++i)
    {
        cout << nums[i] << " ";
    }
	cout << nums[dp[maxi].y];
    return 0;
}