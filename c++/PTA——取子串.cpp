#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{

    string str;
    int b, e;
    while (getline(cin, str))
    {
		
        cin >> b >> e;
        string newstr = str.substr(b-1, e);
        cout << newstr << endl;
		char c = getchar();
    }
    return 0;
}