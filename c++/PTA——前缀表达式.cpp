#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string text;
    stack<float> s;
    stack<string> ss;

    string t;
    while (cin >> t)
    {
        ss.push(t);
    }

    while (!ss.empty())
    {
        t = ss.top();
        ss.pop();

        if (t != "+" && t != "-" && t != "/" && t != "*")
        {
            s.push(atof(t.c_str()));
        }
        else
        {
            float a, b;
            if (t == "+")
            {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(a + b);
            }
            else if (t == "-")
            {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(a - b);
            }
            else if (t == "*")
            {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(a * b);
            }
            else if (t == "/")
            {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();

                if (b == 0)
                {
                    cout << "ERROR" << endl;
                    return 0;
                }

                s.push(a / b);
            }
        }
    }

    printf("%.1f\n", s.top());

    return 0;
}