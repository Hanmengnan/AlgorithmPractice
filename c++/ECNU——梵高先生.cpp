#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> graph(n , vector<int>(n , 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (j == 0 || j == i )
                graph[i][j] = 1;
            else
                graph[i][j] = graph[i - 1][j] + graph[i - 1][j - 1];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            cout << graph[i][j];
            if (j != i )
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}