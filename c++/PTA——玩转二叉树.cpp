#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct node
{
    int n;
    struct node *left, *right;

    node(int x) : n(x), left(NULL), right(NULL) {}
} node;

vector<int> pre, mid;

node *buildTree(int p, int left, int right)
{
    if (left > right)
        return NULL;
    else if (left == right)
        return new node(mid[left]);
    else
    {
        node *root = new node(pre[p]);
        int m = find(mid.begin() + left, mid.begin() + right, pre[p]) - mid.begin();

        root->left = buildTree(p + 1, left, m - 1);
        root->right = buildTree(p + (m - left) + 1, m + 1, right);
        return root;
    }
}

int main()
{
    int n, t;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        mid.push_back(t);
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        pre.push_back(t);
    }
    node *root = buildTree(0, 0, pre.size() - 1);

    queue<node *> q;

    cout << root->n;
    q.push(root->right);
    q.push(root->left);

    while (!q.empty())
    {
        node *t = q.front();
        q.pop();
        if (t != NULL)
        {
            cout << " " << t->n;

            q.push(t->right);
            q.push(t->left);
        }
    }

    return 0;
}