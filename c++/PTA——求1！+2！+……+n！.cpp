#include <iostream>

using namespace std;

int n;
int sum = 0;

void cal(int a, int r)
{
    if (a == n+1)
        return;
    else
    {
        sum += a * r;
        cal(a + 1, a * r);
    }
    return;
}

int main()
{

    cin >> n;
    cal(1, 1);
	cout <<"m="<< sum;
    return 0;
}