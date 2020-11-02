#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <list>

using namespace std;
const int optContainer[8][8] = {{-1, 0, -1, -1, 2, -1, 2, -1}, {2, 1, 1, 1, 2, 1, 2, 1}, {-1, 1, 1, 1, 2, 1, 2, 1}, {-1, 1, -1, 1, 2, 1, 2, -1}, {2, 2, 2, 2, 2, 2, 2, 2}, {-1, 1, -1, 1, 2, 1, 2, -1}, {2, 2, 2, 2, 2, 2, 2, 2}, {-1, 1, 1, 1, 2, 1, 1, 1}};
int isopn(char i);
int optCompare(char opt1, char opt2);
int opt_cal(char i, int a, int b);
int main()
{
    stack<char> optStack;
    stack<int> opnStack;

    string expression;
    cin >> expression;
    int panduan = 0;
    for (unsigned int i = 0; i <= expression.length(); ++i)
    {
        if (isopn(expression[i]))
        {

            if (panduan == 1)
            {
                int temp_num = opnStack.top();
                opnStack.pop();
                opnStack.push(temp_num * 10 + expression[i] - '0');
            }
            else
                opnStack.push(expression[i] - '0');
            panduan = 1;
        }
        else
        {
            panduan = 0;
            if (optStack.empty())
            {
                if (opnStack.empty())
                    exit(0);
                optStack.push(expression[i]);
            }
            else
                switch (optCompare(optStack.top(), expression[i]))
                {
                case 1:
                {
                    char opt = optStack.top();
                    optStack.pop();
                    optStack.push(expression[i]);
                    int opn_a = opnStack.top();
                    opnStack.pop();
                    int opn_b = opnStack.top();
                    opnStack.pop();
                    opnStack.push(opt_cal(opt, opn_a, opn_b));
                    break;
                }
                case 0:
                {
                    optStack.pop();
                    break;
                }
                case -1:
                {
                    optStack.push(expression[i]);
                    break;
                }
                case 3:
                {
                    while (optStack.size() != 0)
                    {
                        char opt = optStack.top();
                        optStack.pop();
                        int opn_a = opnStack.top();
                        opnStack.pop();
                        int opn_b = opnStack.top();
                        opnStack.pop();
                        opnStack.push(opt_cal(opt, opn_a, opn_b));
                    }
                }
                }
        }
    }
    cout << opnStack.top();
    system("pause");
    return 0;
}
int isopn(char i)
{
    if (i <= 57 && i >= 48)
    {
        return 1;
    }
    else
        return 0;
}

int opt_cal(char i, int a, int b)
{
    switch (i)
    {
    case '*':
        return a * b;
    case '/':
        return b / a;
    case '+':
        return a + b;
    case '-':
        return b - a;
    default:
        return 0;
    }
}

int optCompare(char top_opt, char new_opt)
{
    if (new_opt == '\0')
        return 3;

    return optContainer[top_opt - '('][new_opt - '('];
}
