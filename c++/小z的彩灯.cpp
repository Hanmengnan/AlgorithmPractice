#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int flag = 0;
    vector<int> latterns(100000);
    for (int i = 0; i < 100000; ++i)
    {
        cin >> latterns[i]; // = flag;
        // flag = !flag;
    }
    string o;
    while (cin >> o)
    {
        int m, n;

        if (o == "q")
        {
            cin >> m;
            cout << latterns[m];
        }
        else if (o == "a")
        {
            cin >> m >> n;
            for (int i = m; i <= n; ++i)
            {
                latterns[i] = 1;
            }
        }
        else if (o == "b")
        {
            cin >> m >> n;
            for (int i = m; i <= n; ++i)
            {
                latterns[i] = 0;
            }
        }
        else if (o == "c")
        {
            cin >> m >> n;
            for (int i = m; i <= n; ++i)
            {
                latterns[i] = !latterns[i];
            }
        }
    }

    return 0;
}