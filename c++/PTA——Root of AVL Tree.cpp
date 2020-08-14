#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

typedef struct node
{
    int data;
    int height;
    struct node *left, *right;
    node(int data, int height) : data(data), height(height), left(NULL), right(NULL) {}
} node;

int getHeight(node *tree)
{
    if (tree == NULL)
        return 0;
    else
        return tree->height;
}

/*
原左子树重，插入节点还插入到左子树的左子树上
则需要右旋
*/
node *SRR(node *tree)
{
    node *newtree = tree->left;
    tree->left = newtree->right;
    newtree->right = tree;
    tree->height = max(getHeight(tree->left), getHeight(tree->right)) + 1;
    newtree->height = max(getHeight(newtree->left), getHeight(newtree->right)) + 1;
    return newtree;
}

/*
原右子树重，插入节点还插入到右子树的右子树上
则需要左旋
*/
node *SLR(node *tree)
{
    node *newtree = tree->right;
    tree->right = newtree->left;
    newtree->left = tree;
    tree->height = max(getHeight(tree->left), getHeight(tree->right)) + 1;
    newtree->height = max(getHeight(newtree->left), getHeight(newtree->right)) + 1;
    return newtree;
}

/*
原左子树重，插入节点还插入到左子树的右子树上
则需要先左旋再右旋
*/
node *DLRR(node *tree)
{
    node *temp = tree->left;
    tree->left = SLR(temp);
    return SRR(tree);
}

/*
原右子树重，插入节点还插入到右子树的左子树上
则需要先右旋再左旋
*/
node *DRLR(node *tree)
{
    node *temp = tree->right;
    tree->right = SRR(temp);
    return SLR(tree);
}

node *insert(node *tree, int x)
{
    if (tree == NULL)
    //空节点
    {
        tree = new node(x, 1);
    }
    else if (x < tree->data)
    //插入左子树
    {
        tree->left = insert(tree->left, x);
        if (getHeight(tree->left) - getHeight(tree->right) > 1)
        //插入后树失衡
        {
            if (x < tree->left->data)
            //插入到左子树的左子树
            {
                tree = SRR(tree);
            }
            else if (x > tree->left->data)
            //插入到左子树的右子树
            {
                tree = DLRR(tree);
            }
        }
    }
    else if (x > tree->data)
    //插入右子树
    {
        tree->right = insert(tree->right, x);
        if (getHeight(tree->right) - getHeight(tree->left) > 1)
        {
            if (x > tree->right->data)
            //插入到右子树的右子树
            {
                tree = SLR(tree);
            }
            else if (x < tree->right->data)
            //插入到右子树的左子树
            {
                tree = DRLR(tree);
            }
        }
    }
    tree->height = max(getHeight(tree->left), getHeight(tree->right)) + 1;
    return tree;
}

int main()
{
    int n, t;
    cin >> n;
    node *root = NULL;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        root = insert(root, t);
    }
    cout << root->data;
    return 0;
}