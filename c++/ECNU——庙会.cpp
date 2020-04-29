#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 1; i <= k; ++i)
    {
        if (i % m == 0)
            cout << m;
        else
            cout << i % m;
        cout << " ";
		if (i % n == 0)
			cout << n;
		else
			cout << i % n;
		cout<< "\n";
    }
    return 0;
}