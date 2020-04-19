#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &m);
        m = 2 * (m - 1);
        int k = int(sqrt(m));
        if (k * (k + 1) == m)
            printf("1\n");
        else
            printf("0\n");
    }

    return 0;
}