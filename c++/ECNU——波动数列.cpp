#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, s, a, b;
    cin >> n >> s >> a >> b;

    vector<vector<int>> sum(n + 1, vector<int>(s + 1, 0));
    for (int i = 0; i <= s; ++i)
    {
        sum[1][i] = 1;
    }
    return 0;
}