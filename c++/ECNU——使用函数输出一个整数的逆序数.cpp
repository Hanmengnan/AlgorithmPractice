#include <iostream>
#include <queue>

using namespace std;
int reverse(int number);

int main()
{
    int n;
    cin >> n;
    cout << reverse(n) << endl;

    return 0;
}
int reverse(int number)
{

    int new_num = 0;
    while (number)
    {
        new_num = new_num * 10 + number % 10;
        number /= 10;
    }

    return new_num;
}