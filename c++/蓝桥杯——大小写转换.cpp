#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main()
{
    string str;
    while (cin >> str)
    {
        for (int i = 0; i < str.length(); ++i)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                cout << char(str[i] - ('a' - 'A'));
            else
            {
                cout << char(str[i] + ('a' - 'A'));
            }
        }
        cout << endl;
    }
    return 0;
}