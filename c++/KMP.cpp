#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getNextVec(vector<int> &nextVec, string pattern)
{
    int j = 0, k = -1;
    nextVec[0] = -1;

    while (j < pattern.length())
    {
        if (k == -1 || pattern[k] == pattern[j])
        {
            k++;
            j++;
            nextVec[j] = k;
        }
        else
        {
            k = nextVec[k];
        }
    }
    return;
}

int getSubStrIndex(vector<int> next, string str, string pattern)
{
    int i = 0, j = 0;

    while (i < int(str.length()) && j <int( pattern.length()))
    {
        if (j == -1 || str[i] == pattern[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }
    if (j == pattern.length())
    {
        return i - pattern.length() + 1;
    }
    return 0;
}

int main()
{
    int index;
    string str, pattern;
    cin >> str >> pattern;

    vector<int> next(pattern.length() + 1);

    getNextVec(next, pattern);

    cout << getSubStrIndex(next, str, pattern);
    return 0;
}