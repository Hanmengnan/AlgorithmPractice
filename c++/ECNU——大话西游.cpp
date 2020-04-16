#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        vector<vector<int>> graph(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (j == 0 || j == i)
                {
                    graph[i][j] = 1;
                    cout << 1 << " ";
                }
                else
                {
                    graph[i][j] = graph[i - 1][j] + graph[i - 1][j - 1];
                    cout << graph[i - 1][j] + graph[i - 1][j - 1] << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}