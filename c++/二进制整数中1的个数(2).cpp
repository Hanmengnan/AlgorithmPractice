#include <iostream>

using namespace std;

int main()
{
    int num, count;
	cin >> num;
    count = 0;
    while (num)
    {
        count++;
        num = num & (num - 1);
    }
	cout << count;
    return 0;
}