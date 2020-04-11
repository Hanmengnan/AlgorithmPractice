#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string num, subsitute_num;
    map<char, string> digit;
    map<string, char> str;
    digit['0'] = "0000";
    digit['1'] = "0001";
    digit['2'] = "0010";
    digit['3'] = "0011";
    digit['4'] = "0100";
    digit['5'] = "0101";
    digit['6'] = "0110";
    digit['7'] = "0111";
    digit['8'] = "1000";
    digit['9'] = "1001";
    digit['A'] = "1010";
    digit['B'] = "1011";
    digit['C'] = "1100";
    digit['D'] = "1101";
    digit['E'] = "1110";
    digit['F'] = "1111";

    str["000"] = '0';
    str["001"] = '1';
    str["010"] = '2';
    str["011"] = '3';
    str["100"] = '4';
    str["101"] = '5';
    str["110"] = '6';
    str["111"] = '7';

    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        subsitute_num = "";
        for (int j = 0; j < num.length(); ++j)
        {
            subsitute_num += digit[num[j]];
        }
        string temp;
        string result = "";

        int j;
        for (j = subsitute_num.length() - 1; j >= 2; j -= 3)
        {
            temp = string(subsitute_num.begin() + j - 2, subsitute_num.begin() + j + 1);
            result += str[temp];
        }

        if (j < 2 && j >= 0)
        {
            temp = string(subsitute_num.begin(), subsitute_num.begin() + j + 1);
            while (j < 2 && j >= 0)
            {
                temp = '0' + temp;
                j++;
            }
            result += str[temp];
        }
        int flag = 0;
        for (int i = result.length() - 1; i >= 0; --i)
        {
            if (result[i] == '0' && flag == 0)
            {
            }
            else
                cout << result[i];
            flag = 1;
        }
        cout << endl;
    }
    return 0;
}