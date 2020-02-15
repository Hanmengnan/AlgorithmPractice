#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool my_cmp(vector<char> a, vector<char> b)
{
    set<char> set_a(a.begin(), a.end());
    set<char> set_b(b.begin(), b.end());
    string as(a.begin(), a.end());
    string bs(b.begin(), b.end());

    if (set_a.size() != set_b.size())
        return set_a.size() < set_b.size();
    if (a.size() != b.size())
        return a.size() > b.size();
    return as < bs;
}

int main()
{

    int n;
    vector<vector<char>> rank;
    vector<char> str;

    while (cin >> n)
    {
        if (n == 0)
            break;
        getchar();
        rank.clear();

        for (int i = 0; i < n; ++i)
        {
            char c;
            str.clear();
            while ((c = getchar()) != '\n')
            {
                str.push_back(c);
            }
            rank.push_back(str);
        }

        sort(rank.begin(), rank.end(), my_cmp);

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < rank[i].size(); ++j)
            {
                cout << rank[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}