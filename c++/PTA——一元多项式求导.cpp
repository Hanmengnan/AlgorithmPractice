#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a, b;
    int flag = 0;
    while (cin >> a >> b)
    {
        if (b != 0 && a != 0)
        {
            if (flag != 0)
            {
                cout << " ";
            }
            else
            {
                flag = 1;
            }
            cout << a * b << " " << b - 1;
        }
    }
    if (!flag)
        printf("0 0");
    return 0;
}
