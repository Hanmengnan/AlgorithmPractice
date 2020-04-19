#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n, k, m;
    cin >> n >> k;
    vector<int> stairs(n + 1, 1);
    vector<int> ways(n + 1, 0);

    for (int i = 0; i < k; ++i)
    {
        cin >> m;
        stairs[m] = ways[m] = 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (stairs[i])
        {
            if (i == 1)
                ways[i] = 1;
            else if (i == 2)
                ways[i] = ways[i - 1] + 1;
            else if (i == 3)
                ways[i] = ways[i - 1] + ways[i - 2] + 1;
            else
                ways[i] = ways[i - 1] + ways[i - 2] + ways[i - 3];
        }
    }
    cout << ways[n] << endl;
    return 0;
}