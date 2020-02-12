#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int spacenum = n * m - 1;
    for (int i = 1; i <= n; ++i)
    //层数
    {
        for (int j = 1; j <= m; ++j)
        //每个金字塔的层数
        {
            for (int k = 0; k < spacenum; ++k)
            {
                cout << " ";
            }
            spacenum--;
            for (int l = 0; l < (2 * j - 1); ++l)
            {
                cout << "*";
            }
            for (int k = 2; k <= i; ++k)
            {
                for (int l = 0; l < (2 * m - 2 * j + 1); ++l)
                {
                    cout << " ";
                }
                for (int l = 0; l < (2 * j - 1); ++l)
                {
                    cout << "*";
                }
            }
            cout << endl;
        }
    }
    return 0;
}
