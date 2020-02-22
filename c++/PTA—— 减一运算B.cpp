#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int it;
    vector<int> N;
    while (cin >> it)
    {
        N.push_back(it);
    }
    int len = N.size() - 1;

    while (N[len] < 1)
    {
        N[len--] = 9;
    }
    N[len]--;

    int flag = 0;
    for (vector<int>::iterator i = N.begin(); i != N.end(); ++i)
    {
        if (*i != 0 || flag != 0)
        {
            cout << *i << " ";
            flag = 1;
        }
    }
    if (flag == 0)
        cout << 0 << " ";
    return 0;
}