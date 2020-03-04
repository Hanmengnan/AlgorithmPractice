#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int k, n;
    cin >> k >> n;
    vector<vector<int>> digit(n + 1, vector<int>(k));

    for (int i = 0; i < k; ++i)
    {
        digit[1][i] = 1;
    }
    int sum = 0;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            sum = 0;
            for (int l = 0; l < k; ++l)
            {
                if (l != j + 1 && l != j - 1)
                    sum += digit[i - 1][l];
            }
            digit[i][j] = sum;
        }
    }
    sum = 0;
    for (int i = 1; i < k; ++i)
    {
        sum += digit[n][i];
    }
    cout << sum << endl;
    return 0;
}