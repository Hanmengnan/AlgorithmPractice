#include <iostream>
#include <string>

using namespace std;

int main()
{
    string text;
    string pattern;

    cin >> text;
    cin >> pattern;

    int num = 0;
    while (text.find(pattern) != -1)
    {
        int index = text.find(pattern);
        num++;
        text = string(text.begin() + index+1, text.end());
    }
    cout << num;
    return 0;
}