/*这题我真心服了*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
	int n;

	int count[11] = { 0 };

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		getchar();
		count[getchar() - '0']++;
		getchar();
	}
	printf("%d %d %d %d %d\n", count[9] + count[10], count[8], count[7], count[6], (count[0] + count[1] + count[2] + count[3] + count[4] + count[5]));

	return 0;
}