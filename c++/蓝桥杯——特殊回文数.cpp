
#include <iostream>
using namespace std;

int main()
{
	int n, a, b, c, d, e, f;
	cin >> n;
	for (int i = 10000; i < 100000; i++)
	{
		a = i / 10000;
		b = i % 10000 / 1000;
		c = i % 1000 / 100;
		d = i % 100 / 10;
		e = i % 10;
		if (a == e && b == d && a + b + c + d + e == n)
			cout << i << endl;
	}
	for (int j = 100000; j < 1000000; j++)
	{
		a = j % 10;
		b = j % 100 / 10;
		c = j % 1000 / 100;
		d = j % 10000 / 1000;
		e = j % 100000 / 10000;
		f = j / 100000;
		if (a == f && b == e && c == d && a + b + c + d + e + f == n)
			cout << j << endl;
	}
	return 0;
}