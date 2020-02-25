#include <iostream>
#include <string>

using namespace std;

typedef struct node
{
    struct node *left;
    struct node *right;
    char data;
} node;

string treedata;
int index;
int sum = 0;

void createTree(node *root)
{
    if (index == treedata.length())
        return;
    int flag = 0;
    node *leftnode = new node;
    leftnode->left = NULL;
    leftnode->right = NULL;
    leftnode->data = treedata[index];
    root->left = leftnode;
    //左结点
    index++;

    if (leftnode->data != '#')
    {
        createTree(leftnode);
        flag = 1;
    }

    node *rightnode = new node;
    rightnode->left = NULL;
    rightnode->right = NULL;
    rightnode->data = treedata[index];
    root->right = rightnode;
    //右结点
    index++;

    if (rightnode->data != '#')
    {
        createTree(rightnode);
        flag = 1;
    }
    if (flag == 0)
    {
        sum++;
    }

    return;
}

void printTree(node *root, int mode)
{
    if (mode == 0)
    {
        if (root->left->data != '#')
        {
            printTree(root->left, mode);
        }
        cout << root->data;
        if (root->right->data != '#')
        {
            printTree(root->right, mode);
        }
    }
    else
    {
        if (root->right->data != '#')
        {
            printTree(root->right, mode);
        }
        cout << root->data;
        if (root->left->data != '#')
        {
            printTree(root->left, mode);
        }
    }
    return;
}

int main()
{

    cin >> treedata;
    node *root = new node;
    root->left = NULL;
    root->right = NULL;
    root->data = treedata[0];
    index = 1;

    createTree(root);
    printTree(root, 0);
    cout << endl;
    printTree(root, 1);

    return 0;
}