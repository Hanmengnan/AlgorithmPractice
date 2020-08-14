#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    vector<deque<int>> charCount(8);
    int count = 0, flag = 0;
    while (true)
    {
        string str;
        getline(cin, str);

        if (str == ".")
            break;
        else
        {
            for (int i = 0; i < str.length(); ++i)
            {
                if (str[i] == '/' && (i + 1) < str.length() && str[i + 1] == '*')
                {
                    charCount[0].push_back(count);
                    i++;
                }
                else if (str[i] == '(')
                    charCount[1].push_back(count);
                else if (str[i] == '[')
                    charCount[2].push_back(count);
                else if (str[i] == '{')
                    charCount[3].push_back(count);

                else if (str[i] == '*' && (i + 1) < str.length() && str[i + 1] == '/')
                {
                    if (charCount[0].size() > 0)
                    {
                        charCount[0].pop_back();
                    }
                    else
                    {
                        flag = 1;
                        charCount[4].push_back(count);
                    }
                    i++;
                }
                else if (str[i] == ')')
                {
                    if (charCount[1].size() > 0)
                    {
                        charCount[1].pop_back();
                    }
                    else
                    {
                        flag = 1;
                        charCount[5].push_back(count);
                    }
                }
                else if (str[i] == ']')
                {
                    if (charCount[2].size() > 0)
                    {
                        charCount[2].pop_back();
                    }
                    else
                    {
                        flag = 1;
                        charCount[6].push_back(count);
                    }
                }
                else if (str[i] == '}')
                {
                    if (charCount[3].size() > 0)
                    {
                        charCount[3].pop_back();
                    }
                    else
                    {
                        flag = 1;
                        charCount[7].push_back(count);
                    }
                }
                count++;
            }
        }
    }
    int index = -1, num = 9999999;
    for (int i = 0; i < 8; ++i)
    {
        if (charCount[i].size())
        {
            if (charCount[i].front() < num)
            {
                num = charCount[i].front();
                index = i;
                flag = 1;
            }
        }
    }
    if (index == 0)
        cout << "NO" << endl
             << "/*-?";
    else if (index == 1)
        cout << "NO" << endl
             << "(-?";
    else if (index == 2)
        cout << "NO" << endl
             << "[-?";
    else if (index == 3)
        cout << "NO" << endl
             << "{-?";
    else if (index == 4)
        cout << "NO" << endl
             << "?-*/";
    else if (index == 5)
        cout << "NO" << endl
             << "?-)";
    else if (index == 6)
        cout << "NO" << endl
             << "?-]";
    else if (index == 7)
        cout << "NO" << endl
             << "?-}";
    if (flag == 0)
        cout << "YES";
    return 0;
}