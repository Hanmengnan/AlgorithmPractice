#include <iostream>
#include <string>
#include <vector>
using namespace std;

void move(string a, string b, string c, int n)
{
    if (n == 1)
    {
        cout << a << "->" << c << endl;
        return;
    }
    move(a, c, b, n - 1);
    cout << a << "->" << c << endl;
    move(b, a, c, n - 1);
    return;
}

int main()
{
    int n;
    cin >> n;
    string stake1, stake2, stake3;
    cin >> stake1 >> stake2 >> stake3;
    move(stake1, stake2, stake3, n);
    return 0;
}