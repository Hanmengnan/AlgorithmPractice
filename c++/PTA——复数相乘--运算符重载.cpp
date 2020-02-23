#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

void str_to_int(string num, int &real, int &visual)
{
    real = 0, visual = 0;
    string num_real_str;
    string num_visual_str;

    string::iterator num_real_end;
    string::iterator num_real_begin = num.begin();

    string::iterator num_visual_begin;
    string::iterator num_visual_end;

    int num_real_sign = 1;
    int num_visual_sign = 1;

    if (num[num.length() - 1] != 'i')
    //只有实部
    {
        num_visual_sign = 0;
        num_real_end = num.end();
        if (num[0] == '-')
        {
            num_real_sign = -1;
            num_real_begin += 1;
        }
    }
    else
    //存在虚部
    {
        num_visual_end = num.end() - 1;
        string::iterator add_op = find(num.begin(), num.end(), '+');
        string::iterator minus_op = find(num.begin(), num.end(), '-');

        if (add_op != num.end())
        //存在虚部，加号一定是虚部的,并且此时实部虚部同时存在
        {
            num_real_end = add_op; //实部的末尾
            num_visual_begin = add_op + 1;

            if (minus_op != num.end())
            //这时存在负号，肯定是实部的符号
            {
                num_real_sign = -1;  //符号
                num_real_begin += 1; //数字部分
            }
        }

        else if (minus_op != num.end())
        {
            string::iterator minus_2 = find(minus_op + 1, num.end(), '-');
            if (minus_2 == num.end())
            //只有一个负号，只能是虚部
            {
                if (minus_op == num.begin())
                {
                    real = 0;
                    num_real_sign = 0;
                }
                num_real_end = minus_op;
                num_visual_begin = minus_op + 1;
                num_visual_sign = -1;
            }
            else
            //两个负号
            {
                num_real_sign = -1;
                num_real_begin += 1;
                num_real_end = minus_2;
                num_visual_begin = minus_2 + 1;
                num_visual_sign = -1;
            }
        }
        else
        {
            num_real_sign = 0;
            num_visual_begin = num.begin();
        }
    }
    if (num_real_sign != 0)
    {
        num_real_str = string(num_real_begin, num_real_end);

        int len = num_real_str.length() - 1;
        for (int i = len; i >= 0; --i)
        {
            real += pow(10, len) * (num_real_str[len - i] - '0');
        }
        real *= num_real_sign;
    }

    if (num_visual_sign != 0)
    {
        num_visual_str = string(num_visual_begin, num_visual_end);
        if (num_visual_str == "")
            visual = 1;
        else
        {
            int len = num_visual_str.length() - 1;
            for (int i = len; i >= 0; --i)
            {
                visual += pow(10, len) * (num_visual_str[len - i] - '0');
            }
        }
        visual *= num_visual_sign;
    }

    return;
}

int main()
{
    int base_s, base_f, add_s, add_f, add_s2, add_f2;
    base_s = base_f = 0;

    string num1;
    string num2;
    cin >> num1 >> num2;

    str_to_int(num1, add_s, add_f);
    str_to_int(num2, add_s2, add_f2);

    base_s += (add_s * add_s2) - (add_f * add_f2);
    base_f += add_f * add_s2 + add_f2 * add_s;

    if (base_s)
    {
        cout << base_s;
        if (base_f != 0)
        {
            if (base_f > 0)
            {
                cout << "+";
            }
            else
            {
                cout << '-';
            }
            if (abs(base_f) != 1)
                cout << abs(base_f);
            cout << 'i';
        }
    }
    else if (base_f)
    {
        if (base_f < 0)
            cout << "-";
        if (abs(base_f) != 1)
            cout << abs(base_f);
        cout << 'i';
    }
    else
        cout << 0;
    return 0;
}
