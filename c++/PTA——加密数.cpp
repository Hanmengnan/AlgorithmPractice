#include <iostream>
#include <cmath>
#include <vector>

#define ll long long

using namespace std;

int main()
{

    ll n;

    while (cin >> n)
    {
        vector<int> bit_num(32, 0);
        int index = 0;
        
        ll sum = 0;

        if (n < 0)
        {
            n= (long long) (pow(2,32))+n;
        }

        while (n)
        {
            bit_num[index++] = (n % 2);
            n /= 2;
        }

        

        for (int i = 1; i <= 4; ++i)
        {
			int tsum = 0;
			int p = 0;
            for (int j = (i - 1) * 8; j < i * 8; ++j)
            {
                tsum +=(pow(2, p++)) * bit_num[j];
            }
			sum += tsum;
        }
        cout << sum << endl;
    }

    return 0;
}