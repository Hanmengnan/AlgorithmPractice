#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct stu
{
    int sex;
    string name;
    int visit;

} stu;

int main()
{
    int n, k, m;
    cin >> n;

    vector<stu> l;

    int s;
    string na;
    for (int i = 0; i < n; ++i)
    {
        cin >> s >> na;
        l.push_back(stu{s, na, 0});
    }

    int f = l[0].sex;
    for (int i = 0; i < n; ++i)
    {
        if (l[i].visit == 0)
        {
            f = l[i].sex;
            l[i].visit = 1;
            cout << l[i].name << " ";
            for (int j = n - 1; j >= 0; --j)
            {
                if (l[j].visit == 0 && l[j].sex == !f)
                {
                    cout << l[j].name << endl;
                    l[j].visit = 1;
                    break;
                }
            }
        }
    }
    return 0;
}