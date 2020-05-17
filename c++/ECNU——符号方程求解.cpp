#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    string equation;
    int letter, digit;
    char c;
    letter = digit = 0;
    cin >> equation;

    regex pattern("(.*)=(.*)");

    smatch l_r;
    regex_match(equation, l_r, pattern);
    string l = l_r[1];
    string r = l_r[2];

    regex each_pattern("[+-]{0,1}[0-9]*[a-z]{0,1}");
    smatch each_r;
    string::const_iterator b = l.begin();
    string::const_iterator e = l.end();

    while (regex_search(b, e, each_r, each_pattern) && each_r[0] != "")
    {
        string temp = each_r[0];
        if (temp[temp.length() - 1] >= 'a')
        {
            c = temp[temp.length() - 1];
            int flag = 1;
            int i = 0;
            int sum = 0;
            if (temp[0] == '-' || temp[0] == '+')
            {
                i++;
                if (temp[0] == '-')
                    flag = -1;
            }

            for (; i < temp.length() - 1; ++i)
            {
                sum = sum * 10 + temp[i] - '0';
            }
            if (sum == 0)
                sum = 1;
            letter += sum * flag;
        }
        else
        {
            int flag = 1;
            int i = 0;
            int sum = 0;
            if (temp[0] == '-' || temp[0] == '+')
            {
                i++;
                if (temp[0] == '-')
                    flag = -1;
            }

            for (; i < temp.length(); ++i)
            {
                sum = sum * 10 + temp[i] - '0';
            }
            digit += sum * flag;
        }

        b = each_r[0].second;
    }
    b = r.begin();
    e = r.end();
    while (regex_search(b, e, each_r, each_pattern) && each_r[0] != "")
    {
        string temp = each_r[0];
        if (temp[temp.length() - 1] >= 'a')
        {
            c = temp[temp.length() - 1];
            int flag = -1;
            int i = 0;
            int sum = 0;
            if (temp[0] == '-' || temp[0] == '+')
            {
                i++;
                if (temp[0] == '-')
                    flag = 1;
            }

            for (; i < temp.length() - 1; ++i)
            {
                sum = sum * 10 + temp[i] - '0';
            }
            if (sum == 0)
                sum = 1;
            letter += sum * flag;
        }
        else
        {
            int flag = -1;
            int i = 0;
            int sum = 0;
            if (temp[0] == '-' || temp[0] == '+')
            {
                i++;
                if (temp[0] == '-')
                    flag = 1;
            }

            for (; i < temp.length(); ++i)
            {
                sum = sum * 10 + temp[i] - '0';
            }
            digit += sum * flag;
        }

        b = each_r[0].second;
    }
    if (digit != 0)
        printf("%c=%.3f\n", c, digit * -1.0 / letter);
    else
        printf("%c=%.3f\n", c, 0.00);
    return 0;
}