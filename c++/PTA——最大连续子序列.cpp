#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        vector<int> num(n + 1);
        vector<int> dp(n + 1);
        int max_num = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> num[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            dp[i] = max(dp[i - 1] + num[i], num[i]);
            if (dp[i] > max_num)
                max_num = dp[i];
        }
		cout << max_num << endl;
    }
}