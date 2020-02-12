#include <iostream>
#include <string>

using namespace std;

int main()
{

    int m, n, d;
    cin >> m >> n >> d;
    if (n <= 0 || d <= 0 || m <= 0)
    {
        cout << "data input error!";
    }
    else
    {
        cout << m / n << ".";

        for (int i = 0; i < d; ++i)
        {
            m = m % n;
            m *= 10;
            cout << m / n;
        }
    }
    return 0;
}