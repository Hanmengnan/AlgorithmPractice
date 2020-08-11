#include <iostream>
#include <string>
using namespace std;

typedef struct node
{
    struct node *right, *left;
    char c;
} node;

string str;
int index = 0, num = 0;

node *creatNode()
{
    node *p = (node *)malloc(sizeof(node));
    p->left = p->right = NULL;
    return p;
}

node *buildTree()
{
    if (str[index] == '#')
    {
        index++;
        return NULL;
    }
    else
    {
        node *root = creatNode();
        root->c = str[index++];
        root->left = buildTree();
        root->right = buildTree();
        if (root->left == NULL && root->right == NULL)
            num++;
        return root;
    }
}

void midOrderPrint(node *root)
{
    if (root == NULL)
        return;
    midOrderPrint(root->left);
    cout << root->c;
    midOrderPrint(root->right);
}

int main()
{
    cin >> str;
    node *root = buildTree();
    midOrderPrint(root);
    cout << endl
         << num;
    return 0;
}