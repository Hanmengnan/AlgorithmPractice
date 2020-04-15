#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main()
{
    int n, m;
    int count = 1;
    while (cin >> n, n)
    {
        map<string, int> money;
        string name;
        for (int i = 0; i < n; ++i)
        {
            cin >> name;
            money[name] = i;
        }

        vector<vector<double>> graph(n, vector<double>(n, 0));
        for (int i = 0; i < n; ++i)
        {
            graph[i][i] = 1;
        }
        cin >> m;

        string m1, m2;
        double rate;
        for (int i = 0; i < m; ++i)
        {
            cin >> m1 >> rate >> m2;
            graph[money[m1]][money[m2]] = rate;
        }

        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (graph[i][j] < graph[i][k] * graph[k][j])
                        graph[i][j] = graph[i][k] * graph[k][j];
        int flag = 0;
        for (int i = 0; i < n; ++i)
        {
            if (graph[i][i] > 1)
                flag = 1;
        }
        if (flag)
            cout << "Case " << count << ": Yes" << endl;
        else
            cout << "Case " << count << ": No" << endl;
		count++;
    }
    return 0;
}