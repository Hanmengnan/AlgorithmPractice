#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        ll n, b;
        cin >> n >> b;
        int i;
        for (i = 0; i < 9973; i++)
            if ((((b % 9973) * i) % 9973 - n) % 9973 == 0)
            {
                break;
            }
        printf("%d\n", i);
    }
    return 0;
}