#include <iostream>
#include <vector>

using namespace std;

typedef struct node
{
    int left;
    int right;
} node;

node *tree;

void traversal(int root)
{
    if (root)
        cout << root << " ";

    if (tree[root].left)
        traversal(tree[root].left);
    if (tree[root].right)
        traversal(tree[root].right);
}

int main()
{

    int n;
    cin >> n;
    tree = new node[n + 1];
    for (int i = 1; i <= n; ++i)
    {

        cin >> tree[i].left;
        cin >> tree[i].right;
    }
    traversal(1);
    return 0;
}