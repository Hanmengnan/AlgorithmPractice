#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    int m, n;
    cin >> m >> n;
    double t = sqrt(m * m - 4 * n);
    double t1 = double(m + t) / 2;
    double t2 = double(m - t) / 2;

    if (t1 - int(t1) != 0 || t2 - int(t2) != 0)
        cout << "No";
    else
        cout << "Yes";
    return 0;
}