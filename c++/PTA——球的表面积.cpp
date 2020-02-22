#include <iostream>

using namespace std;

int main()
{
    double n;

    while (cin >> n)
    {
        if (n < 0)
            cout << "Sorry" << endl;
        /*else if (int(n) == 0)
            cout << 0 << endl;*/
        else
        {
            printf("%g\n", 3.14*n*n);
        }
    }

    return 0;
}