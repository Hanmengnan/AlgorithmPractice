#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    int x, y;
    cin >> x >> y;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {

        if (nums[i] > y || nums[i] < x)
        {
            if (flag != 0)
            {
                cout << " ";
            }
            cout << nums[i];
            flag = 1;
        }
    }
    return 0;
}