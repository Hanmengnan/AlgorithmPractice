#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int num = 0;
    while (cin >> str)
    {
        int i = 0;
        if (num == 0)
        {
            num = 1;
        }
        else
        {
            cout << endl
                 << endl;
        }
        while (i < str.length())
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
                cout << char(str[i] + 32);
            else if (str[i] >= 'a' && str[i] <= 'z')
                cout << char(str[i] - 32);
            else
                cout << str[i];
            i++;
        }
        num = 1;
    }
    return 0;
}