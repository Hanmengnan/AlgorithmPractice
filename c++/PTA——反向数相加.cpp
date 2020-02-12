#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
char a[2000];
char b[2000];
int c[2002];
int lowbit(int y)
{
    return y & (-y);
}
int find(char *x)
{
    int sum = 0;
    int len = strlen(x);
    for (int i = len - 1; i >= 0; i--)
    {
        sum = sum * 10 + (x[i] - '0');
    }
    //cout<<sum<<endl;
    return sum;
}
int find1(int y)
{
    memset(c, 0, sizeof(c));
    //cout<<y<<endl;
    int i = 0;
    int t = 0;
    //y=lowbit(y);
    while (y > 0)
    {
        t = y % 10;
        y /= 10;
        i++;
        c[i] = t;
    }
    //	cout<<endl;
    int sum = 0;
    for (int j = 0; j <= i; j++)
        sum = sum * 10 + c[j];
    cout << sum << endl;
    return sum;
}
int main()
{
    int n, sum;

    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        sum = find(a) + find(b);
        sum = find1(sum);
        //sum=find(sum);
        //	cout<<sum<<endl;
    }
    return 0;
}