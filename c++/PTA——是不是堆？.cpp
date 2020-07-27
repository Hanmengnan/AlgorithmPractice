#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, t, flag;
    cin >> n;

    vector<unsigned int> list(1000001);

    scanf("%d", &list[1]);
    scanf("%d", &list[2]);

    if (list[1] > list[2])
        flag = 1;
    else
        flag = 0;

    for (int i = 3; i <= n; ++i)
    {
        scanf("%d", &list[i]);

        if ((list[i] < list[i / 2]) ^ flag)
        {
            cout << "not a heap";
            return 0;
        }
    }

    if (flag)
        cout << "max heap";
    else
        cout << "min heap";
    return 0;
}