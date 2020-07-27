#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, t;
    cin >> n;

    vector<int> list(n + 1, 0);

    for (int i = 0; i < 3 * n - 1; ++i)
    {
        scanf("%d", &t);
        list[t]++;
    }

    for (int i = 1; i < n; ++i)
    {
        if (list[i] == 2)
            cout << i;
    }
    return 0;
}