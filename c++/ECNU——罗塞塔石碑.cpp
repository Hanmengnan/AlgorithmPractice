#define INF 999999
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{

    int m, n;
    cin >> m >> n;
    vector<vector<int>> graph(26, vector<int>(26, INF));
    char a, b;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        graph[a - 'a'][b - 'a'] = 1;
    }
    for (int i = 0; i < 26; ++i)
        graph[i][i] = 1;
    for (int k = 0; k < 26; ++k)
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
            {
                if (i == k || j == k)
                    continue;
                if (graph[i][k] != INF && graph[k][j] != INF && graph[i][j] == INF)
                    graph[i][j] = 1;
            }

    string str_1, str_2;
    for (int i = 0; i < n; ++i)
    {
        cin >> str_1 >> str_2;
        if (str_1.length() != str_2.length())
            cout << "no" << endl;
        else
        {
            for (int j = 0; j < str_1.length(); ++j)
            {
                if (graph[str_1[j] - 'a'][str_2[j] - 'a'] != 1)
                {
                    cout << "no" << endl;
                    goto next;
                }
            }
            cout << "yes" << endl;
        next:;
        }
    }

    return 0;
}