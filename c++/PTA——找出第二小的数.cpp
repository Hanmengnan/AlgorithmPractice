#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int m;
        cin >> m;

        set<int> num;

        int temp;

        for (int j = 0; j < m; ++j)
        {
            cin >> temp;
            num.insert(temp);
        }
        if (num.size() < 2)
            cout << "NO" << endl;
        else
        {
            set<int>::iterator it = num.begin();
            cout << *(++it)<<endl;
        }
    }
    return 0;
}