#include <iostream>

using namespace std;

void GetTwoInts(int &m, int &n)
{
    scanf("%d%d", &m, &n);
}
int main()
{
    int m, n;
    GetTwoInts(m, n);
    cout << m + n << endl;
    return 0;
}