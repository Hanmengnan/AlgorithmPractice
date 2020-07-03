#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n;
    char c;
    string str;
    cin >> n >> c;
	getchar();
    getline(cin, str);

    if (str.length() > n)
    {
        for (int i = str.length() - n; i < str.length(); ++i)
        {
            cout << str[i] ;
        }
    }
    else
    {
        for (int i = 0; i < n - str.length(); ++i)
        {
            cout << c;
        }
        cout << str;
    }
    return 0;
}
