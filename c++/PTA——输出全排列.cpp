#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

void swap(vector<int> &list, int a, int b)
{
    int n = max(a, b);
    int m = min(a, b);
    int t = list[n];
    for (int i = n; i > m; --i)
    {
        list[i] = list[i-1];
    }
    list[m] = t;
}

void swap_back(vector<int> &list, int a, int b)
{
    int n = max(a, b);
    int m = min(a, b);
    int t = list[m];
    for (int i = m; i < n; ++i)
    {
        list[i] = list[i + 1];
    }
    list[n] = t;
}

void output(vector<int> &nums, int p, int q)
{
    if (p == q)
    {
        for (int i = 0; i < q + 1; ++i)
            cout << nums[i];
        cout << endl;
    }
    else
    {
        for (int i = p; i <= q; ++i)
        {
            swap(nums, i, p);

            output(nums, p + 1, q);

            swap_back(nums, i, p);
        }
    }
}

int main()
{

    cin >> n;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    output(nums, 0, n - 1);
    return 0;
}