#include <iostream>
#include <cmath>

using namespace std;

bool prime(int x)
{
    for (int i = 2; i < int(sqrt(x)) + 1; ++i)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{

    int n;
    while (cin >> n)
    {
        if (prime(n))
            cout << "YES"
                 << " " << n * n << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}