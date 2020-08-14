#include <iostream>
#include <vector>

using namespace std;

typedef struct node
{
    struct node *left, *right;
    int data;
    node(int x) : left(NULL), right(NULL), data(x) {}
} node;

node *buildTree(node *root, int x)
{
    if (root == NULL)
    {
        return new node(x);
    }
    else if (x < root->data)
    {
        root->left = buildTree(root->left, x);
        return root;
    }
    else if (x > root->data)
    {
        root->right = buildTree(root->right, x);
        return root;
    }
}

void visitTree(vector<int> &vec, int index, node *root)
{
    if (index > 10)
        return;
    if (root == NULL)
    {
        vec[index] == 0;
    }
    else
    {
        vec[index] = root->data;
        visitTree(vec, index * 2, root->left);
        visitTree(vec, index * 2 + 1, root->right);
    }
}

int main()
{
    int n, m, x;
    while (true)
    {
        cin >> n;
        if (n == 0)
            return 0;
        cin >> m;

        vector<int> order(11);
        vector<int> real(11);

        for (int f = 0; f < m + 1; ++f)
        {
            if (f == 0)
            {
                order.clear();
                order.resize(11);
                node *root = NULL;
                for (int i = 0; i < n; ++i)
                {
                    cin >> x;
                    root = buildTree(root, x);
                }
                visitTree(order, 1, root);
            }
            else
            {
                real.clear();
                real.resize(11);
                node *root = NULL;
                for (int i = 0; i < n; ++i)
                {
                    cin >> x;
                    root = buildTree(root, x);
                }
                visitTree(real, 1, root);
                int flag = 0;
                for (int i = 1; i < 11; ++i)
                {
                    if (order[i] != real[i])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    cout << "Yes" << endl;
                }
                else
                {
                    cout << "No" << endl;
                }
            }
        }
    }
    return 0;
}