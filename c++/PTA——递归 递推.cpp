#include <iostream>

using namespace std;

int sum;
int n, f1, a, b;

int cal(int i, int a, int b, int fn)
{
    if (i == n)
        return fn;
    return cal(i + 1, a, b, a * fn + b);
}

int main()
{

    while (cin >> n >> f1 >> a >> b)
    {
        cout << cal(1, a, b, f1) << endl;
    }
    return 0;
}