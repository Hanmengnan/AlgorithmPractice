#include <iostream>
#define ll long long

using namespace std;

int main()
{

    ll n;
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> n;
        int num = 0;
        while (n)
        {
            num += (n / 5);
            n /= 5;
        }
        cout << num << endl;
    }
    return 0;
}