#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        int max = -1;
        for (int j = 0; j < m; ++j)
        {
            int temp;
            cin >> temp;
            if (max < temp)
                max = temp;
        }
        sum += max;
    }
    cout << sum;
    return 0;
}