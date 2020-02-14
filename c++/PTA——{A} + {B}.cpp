#include <iostream>
#include <set>
using namespace std;

int main()
{

    int m, n;
    set<int> con1;
    set<int> con2;
    int p = 0;
    while (cin >> m >> n)
    {
        con1.clear();
        con2.clear();
        int num;
        for (int i = 0; i < m; ++i)
        {
            cin >> num;
            con1.insert(num);
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> num;
            con1.insert(num);
        }
        con1.insert(con2.begin(), con2.end());
        for (set<int>::iterator i = con1.begin(); i != con1.end(); ++i)
        {
            if (i == con1.begin())
                cout << *i;
            else
                cout << " " << *i;
        }
        cout << endl;
    }
    return 0;
}