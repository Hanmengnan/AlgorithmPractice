#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n;
    cin >> n;
    vector< vector<int> > matrix(n, vector<int>(n,0));
    int num = 1;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            matrix[i][j] = num++;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%3d", matrix[i][j]);
        }
        cout << endl;
    }
    return 0;
}