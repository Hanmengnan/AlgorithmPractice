#include <iostream>

using namespace std;

void cal(int n, int &m)
{
    if (n == 1)
    {
        return;
    }
    m++;
    {
        if (n % 2)
        {
            cal((3 * n + 1)/2, m);
        }
        else
            cal(n / 2, m);
    }
}
int main()
{
    int n, m;
    while (cin >> n)
    {
        m = 0;
        cal(n, m);
        cout << m << endl;
    }
    return 0;
}