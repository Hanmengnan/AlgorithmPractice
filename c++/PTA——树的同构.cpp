#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct node
{
    string c;
    int left, right;
} node;

vector<node> first, second;

bool isSameTree(int root1, int root2)
{
    if (root1 == -1 && root2 != -1 || root2 == -1 && root1 != -1)
        return false;
    else if (root1 == -1 && root2 == -1)
        return true;
    else
    {
        string c1 = first[root1].c, c2 = second[root2].c;

        bool flag = false;
        bool flag1, flag2;
        if (c1 == c2)
        {
            flag1 = isSameTree(first[root1].left, second[root2].left) && isSameTree(first[root1].right, second[root2].right);
            flag2 = isSameTree(first[root1].left, second[root2].right) && isSameTree(first[root1].right, second[root2].left);
            return flag1 || flag2;
        }
        else
        {
            return false;
        }
    }
}

void initVec(vector<node> &vec, vector<int> &du, int n)
{
    string c, l, r;
    int tl, tr;
    for (int i = 0; i < n; ++i)
    {
        cin >> c >> l >> r;

        if (l != "-")
        {
            tl = atoi(l.c_str());
            du[tl]++;
        }
        else
            tl = -1;

        if (r != "-")
        {
            tr = atoi(r.c_str());
            du[tr]++;
        }
        else
            tr = -1;

        vec.push_back(node{c, tl, tr});
    }
}

int main()
{
    int n, m;
    cin >> n;
    getchar();

    vector<int> du1(10), du2(10);
    initVec(first, du1, n);

    cin >> m;

    if (n != m)
        cout << "No";
    else if (n == 0 && m == 0)
        cout << "Yes";
    else
    {
        initVec(second, du2, m);

        int root1, root2;

        for (int i = 0; i < n; ++i)
        {
            if (du1[i] == 0)
                root1 = i;
            if (du2[i] == 0)
                root2 = i;
        }

        if (isSameTree(root1, root2))
        {
            cout << "Yes";
        }
        else
            cout << "No";
    }

    return 0;
}