#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, i, j;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n, 0));
	a[0][0] = 1;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (i == j)
			{
				a[i][j] = 1;
				cout << "1";
			}
			else if (j == 0)
			{
				a[i][j] = 1;
				cout << "1 ";
			}
			else
			{
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
				printf("%d ", a[i][j]);
			}
		}
		cout << endl;
	}
	return 0;
}