#include <iostream>
#include <cmath>
#define ll long long

using namespace std;

int main()
{

    int m, n;
    cin >> m >> n;

    int sum = 1;
    for (int i = n - m + 1; i <= n; ++i)
    {
        sum *= i;
    }
    int temp = 1;
    for (int i = 1; i <= m; ++i)
    {
        temp *= i;
    }
    cout <<sum<<" "<< sum / temp;
    return 0;
}