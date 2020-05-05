#define ll long long
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
ll c[2010][2010];

int main()
{
    ll mod = 1e9 + 7;

    string name, aim;
    cin >> name;
    int q, n;
    cin >> q;

    for (int i = 0; i <= 2000; i++)
        c[i][0] = 1;
    for (int i = 1; i <= 2000; i++)
        for (int j = 1; j <= i; j++)
        {
            c[i][j] += c[i - 1][j] + c[i - 1][j - 1];
            c[i][j] %= mod;
        }

    while (q--)
    {
        cin >> n >> aim;
        if (n > name.length() || n < 2)
        {
            cout << 0 << endl;
            continue;
        }
        vector<vector<int>> c_index(2, vector<int>(2000, 0));
        vector<vector<int>> index_list(2);
        for (int i = 0; i < 2; ++i)
        {
            int index = -1;
            while (true)
            {
                index = name.find(aim[i], index + 1);
                if (index != string::npos)
                {
                    c_index[i][index] = 1;
                    index_list[i].push_back(index);
                }
                else
                {
                    break; 
                }
            }
        }

        ll sum = 0;
        for (int i = 0; i < index_list[0].size(); ++i)
        {
            ll tail = count(c_index[1].begin() + index_list[0][i] + 1, c_index[1].end(), 1);
            ll head = c[index_list[0][i]][n - 2];
            sum += head * tail;
            sum %= 1000000007;
        }
        cout << sum << endl;
    }
    return 0;
}