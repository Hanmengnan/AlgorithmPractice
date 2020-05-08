#include <string>
#include <iostream>

using namespace std;

int sum(int n)
{
    int m = 0;
    while (n)
    {
        m += n % 10;
        n /= 10;
    }
    return m;
}

int reserve_num(int n)
{
    int m = 0;
    while (n)
    {
        m = m * 10 + n % 10;
        n /= 10;
    }
    return m;
}

int main()
{
    int count = 0;
    int n;
    cin >> n;
    for (int i = 10000; i <= 999999; ++i)
    {
        if (sum(i) == n && i == reserve_num(i))
        {
			cout <<i << endl;
			count = 1;
        }
    }
	if (!count)cout << -1;


    return 0;
}