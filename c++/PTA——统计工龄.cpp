#include <iostream>

using namespace std;

int main()
{
    int count[51] = {0};
    int n, t;
    cin >> n;
    while (n--)
    {
        cin >> t;
        count[t]++;
    }
    for (int i = 0; i < 51; ++i)
    {
        if (count[i])
        {
            cout << i << ":" << count[i] << endl;
        }
    }
    return 0;
}