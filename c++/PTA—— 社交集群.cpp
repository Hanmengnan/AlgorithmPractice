#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int fa[N], a[N], num[N];
int Find(int x)
{
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}
int Union(int a, int b)
{
    a = Find(a), b = Find(b), fa[a] = b;
    return a != b;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < N; i++)
        fa[i] = i;
    for (int i = 0, x, y; i < n; i++)
    {
        scanf("%d: %d", &x, &y), a[i] = y;
        for (int j = 1, z; j < x; j++)
            cin >> z, Union(y, z);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        num[Find(a[i])]++;
    for (int i = 0; i < N; i++)
        if (num[i])
            cnt++;
    sort(num, num + N, greater<int>());
    printf("%d\n", cnt);
    printf("%d", num[0]);
    for (int i = 1; i < cnt; i++)
        printf(" %d", num[i]);
    printf("\n");
    return 0;
}