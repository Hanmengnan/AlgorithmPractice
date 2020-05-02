#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int sum(string str, int n)
{
    if (n == -1)
        return 0;
    else
    {
        if (str.find("101") != string::npos)
            return int(pow(2, n));
        else
        {
            return sum(str + "0", n - 1) + sum(str + "1", n - 1);
        }
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == -1)
            break;
        if (n < 3)
            cout << int(pow(2, n)) << endl;
        else if (n == 3)
            cout << 7 << endl;
        else
        {
            int count = int(pow(2, n - 3));
            count += sum("000", n - 3);
            count += sum("001", n - 3);
            count += sum("010", n - 3);
            count += sum("011", n - 3);
            count += sum("100", n - 3);
            count += sum("110", n - 3);
            count += sum("111", n - 3);
            cout << int(pow(2, n)) - count << endl;
        }
    }
    return 0;
}