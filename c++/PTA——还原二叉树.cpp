#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<char> preOrder;
vector<char> midOrder;

int num = 0;

typedef struct node
{
    char data;
    struct node *left, *right;
    node(char x) : data(x), left(NULL), right(NULL) {}
} node;

node *buildTree(int aim, int left, int right)
{
    if (left == right)
    {
        return new node(preOrder[aim]);
    }
    else if (left > right)
        return NULL;
    else
    {
        node *root = new node(preOrder[aim]);
        int index = find(midOrder.begin(), midOrder.end(), preOrder[aim]) - midOrder.begin();

        root->left = buildTree(aim + 1, left, index - 1);
        root->right = buildTree(aim + (index - left) + 1, index + 1, right);
        return root;
    }
}

int getDeepth(node *root)
{
    if (root == NULL)
        return 0;
    int a = getDeepth(root->left);
    int b = getDeepth(root->right);
    return a > b ? (a + 1) : (b + 1);
}

int main()
{
    int n;
    cin >> n;

    char t;
	getchar();
    for (int i = 0; i < n; ++i)
    {
        t = getchar();
        preOrder.push_back(t);
    }
	getchar();
    for (int i = 0; i < n; ++i)
    {
        t = getchar();
        midOrder.push_back(t);
    }

    node *root = buildTree(0, 0, n - 1);

    cout << getDeepth(root);

    return 0;
}