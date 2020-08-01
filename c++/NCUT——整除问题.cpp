#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    if (m % n == 0)
        printf("YES");
    else
        printf("NO");
    return 0;
}