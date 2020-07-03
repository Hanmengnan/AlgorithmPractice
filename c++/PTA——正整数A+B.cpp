#include <iostream>
#include <string>

using namespace std;

int is_digits(string str)
{
    int sum = 0;
    for (string::iterator i = str.begin(); i < str.end(); ++i)
    {
        if (*i >= '0' && *i <= '9')
        {
            sum = sum * 10 + (*i - '0');
        }
        else
        {
            return -1;
        }
    }
    if (sum < 1 || sum > 1000)
    {
        return -1;
    }
    else
    {
        return sum;
    }
}

int main()
{
    string a, b;
    while (cin >> a)
    {
		getline(cin, b);
        int ra = is_digits(a);
        int rb = is_digits(b);
        int f = 0;
        if (ra == -1)
        {
            f = 1;
            cout << "?";
        }
        else
        {
            cout << ra;
        }
        cout << " + ";
        if (rb == -1)
        {
            f = 1;
            cout << "?";
        }
        else
        {
            cout << rb;
        }
        cout << " = ";
        if (f)
        {
            cout << "?";
        }
        else
        {
            cout << ra + rb;
        }
    }
    return 0;
}