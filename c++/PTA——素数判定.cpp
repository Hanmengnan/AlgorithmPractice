#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> state(90);
bool prime(int x)
{
    for (int i = 2; i < int(sqrt(x)) + 1; ++i)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    for (int i = -39; i <= 50; ++i)
    {
        if (!prime(i * i + i + 41))
        {
            state[i + 39] = 1;
        }
    }
    int a, b;
    while (cin >> a >> b)
    {
        

        if (a == 0 && b == 0)
            return 0;
        vector<int>::iterator r = find(state.begin() + (a + 39), state.begin() + (b + 40), 1);
        if (r == state.begin() + (b + 40))
        {
            cout << "OK" << endl;
        }

        else
            cout << "Sorry" << endl;
    }
    return 0;
}