#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    vector<int> nums(10000005, 0);
    nums[1] = 1;

    for (int i = 1; i < 10000001; ++i)
    {
        if (i % 2 == 0)
        {
            nums[i] = 1;
        }
    }
    nums[1] = 1;
    nums[2] = 0;

    for (int i = 1; i < sqrt(10000001); ++i)
    {
        if (nums[i] == 0)
        {
            for (int j = i * i; j < 10000001; j += i)
            {
                nums[j] = 1;
            }
        }
    }
    cout << 2;
    for (int i = 3; i < 10000001; ++i)
    {
        if (nums[i] == 0)
        {
            cout << " " << i;
        }
    }

    return 0;
}