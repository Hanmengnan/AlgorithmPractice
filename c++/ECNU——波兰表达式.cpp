#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main()
{
    vector<string> temp;
    stack<float> digit;
    stack<string> operators;

    string expression;
     while (cin >> expression )
    {
        temp.push_back(expression);
		if (cin.get() == '\n') break;
    }

    for (int i = temp.size() - 1; i >= 0; --i)
    {
        if (temp[i] == "+")
        {
            float op1 = digit.top();
            digit.pop();
            float op2 = digit.top();
            digit.pop();
            digit.push(op1 + op2);
        }
        else if (temp[i] == "-")
        {
            float op1 = digit.top();
            digit.pop();
            float op2 = digit.top();
            digit.pop();
            digit.push(op1 - op2);
        }
        else if (temp[i] == "*")
        {
            float op1 = digit.top();
            digit.pop();
            float op2 = digit.top();
            digit.pop();
            digit.push(op1 * op2);
        }
        else if (temp[i] == "/")
        {
            float op1 = digit.top();
            digit.pop();
            float op2 = digit.top();
            digit.pop();
            digit.push(op1 / op2);
        }
        else
        {
            digit.push(atof(temp[i].c_str()));
        }
    }
    printf("%.6f\n", digit.top());
    return 0;
}