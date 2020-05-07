#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    string str;
    cin >> str;
    vector<int> len(51, 1);
    for (int i = 1; i < str.length(); ++i)
    {
        if (str[i] != str[i - 1])
            len[i] = len[i - 1] + 1;
    }
    int max = 1;
    for (int i = 1; i < str.length(); ++i)
    {
        if (len[i] > max)
            max = len[i];
    }
    cout << max;
    return 0;
}