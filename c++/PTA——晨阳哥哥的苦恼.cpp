#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_prime(int x)
{
    for (int i = 2; i <= int(sqrt(x)) + 1; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    vector<int> num(1001);
    for (int i = 2; i <= 1000; ++i)
    {
        if (is_prime(i))
            num[i] = 1;
    }
    int a;
    while (cin >> a)
    {
        int sum = 0;
        for (int i = a; i > 1; --i)
        {
            if (num[i] && num[i - 2])
            {
             /*   cout<<i<<" ";*/
                sum++;
            }
        }
        cout << sum << endl;
    }

    return 0;
}