#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    char l, r;
    cin >> n;
    if (n == 1)
    {
        cout << 0;
        return 0;
    }

    vector<vector<int>> treeVec(n, vector<int>(2));
    vector<int> vis(n, 0);
    getchar();

    for (int i = 0; i < n; ++i)
    {
        scanf("%c %c", &l, &r);
        getchar();

        if (l == '-')
            treeVec[i][0] = -1;
        else
        {
            int left = l - '0';
            treeVec[i][0] = left;
            vis[left] = 1;
        }
        if (r == '-')
            treeVec[i][1] = -1;
        else
        {
            int right = r - '0';
            treeVec[i][1] = right;
            vis[right] = 1;
        }
    }

    int i, flag = 0;
    for (i = 0; i < n; ++i)
    {
        if (vis[i] == 0)
            break;
    }

    queue<int> nodes;
    nodes.push(i);
    
    while (!nodes.empty())
    {
        i = nodes.front();
        nodes.pop();
        if (treeVec[i][0] == -1 && treeVec[i][0] == -1)
        {
            if (flag == 0)
                cout << i;
            else
                cout << " " << i;
            flag = 1;
        }
        if (treeVec[i][0] != -1)
        {
            nodes.push(treeVec[i][0]);
        }
        if (treeVec[i][1] != -1)
        {
            nodes.push(treeVec[i][1]);
        }
    }
    return 0;
}