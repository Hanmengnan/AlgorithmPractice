#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;
int search(int b, int e, int aim)
{
    if (b > e)
        return -1;
    int mid = (b + e) / 2;
    if (nums[mid] == aim)
        return mid;
    else if (nums[mid] > aim)
    {
        return search(b, mid - 1, aim);
    }
    else
    {
        return search(mid + 1, e, aim);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int t;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        nums.push_back(t);
    }

    int aim;
    for (int i = 0; i < m; ++i)
    {
        cin >> aim;
        int r = search(0, n - 1, aim);
        if (r != -1)
        {
            cout << n - r << endl;
        }
        else
            cout << "meiyou" << endl;
    }
    return 0;
}