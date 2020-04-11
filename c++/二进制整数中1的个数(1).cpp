#include <iostream>

using namespace std;

int main()
{
    int num, count;
    count = 0;
    cin >> num;
    while (num)
    {
        if (num & 1)
            count++;
        num = num >> 1;
    }
    cout << count;
	return 0;
}