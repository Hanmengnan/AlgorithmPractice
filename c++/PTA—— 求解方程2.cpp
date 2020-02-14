#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
	if (b*b < 4 * a*c) cout << "No" << endl;
	else if (b*b == 4 * a*c) {
		double r1 = double(-1 * b) / (2 * a);
		printf("%.2f\n", r1);
	}
	else {
		if (a != 0)
		{
			double t = sqrt(b * b - 4 * a * c);
			double r1 = (-1 * b + t) / (2 * a);
			double r2 = (-1 * b - t) / (2 * a);
			printf("%.2f %.2f\n", (r1 < r2 ? r1 : r2), (r1 >= r2 ? r1 : r2));
		}
		else
		{
			if (b == 0)
				cout << "No" << endl;
			else
				printf("%.2f\n", -1 * double(c) / double(b));
		}
	}
    return 0;
}