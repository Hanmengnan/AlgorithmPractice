#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    vector<string> strVec;
    string str;
    while (getline(cin, str) && str[0] != '\0')
    {

        strVec.push_back(str);
    }

    while (cin>>str)
    {
        int count = 0;
        for (int i = 0; i < strVec.size(); ++i)
        {
            if (str.length() > strVec[i].length())
                continue;
            if (str == string(strVec[i].begin(), strVec[i].begin() + str.length()))
                count++;
        }
        cout << count << endl;
    }

    return 0;
}