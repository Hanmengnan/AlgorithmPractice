#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct node
{
    struct node *left, *right;
    string data;
    node(string x) : left(NULL), right(NULL), data(x) {}
} node;

vector<string> preOrder, inOrder;

node *buildTree(int aim, int i, int j)
{
    if (i > j)
        return NULL;
    if (i == j)
    {
        return new node(inOrder[i]);
    }

    int mid = find(inOrder.begin() + i, inOrder.begin() + j, preOrder[aim]) - inOrder.begin();

    node *root = new node(inOrder[mid]);
    root->left = buildTree(aim + 1, i, mid - 1);
    root->right = buildTree(aim + (mid - i) + 1, mid + 1, j);

    return root;
}

void initOrder(int n)
{
    stack<string> strStack;

    string operators, num;

    for (int i = 0; i < 2 * n; ++i)
    {
        cin >> operators;
        if (operators == "Push")
        {
            cin >> num;
            preOrder.push_back(num);
            strStack.push(num);
        }
        else
        {
            num = strStack.top();
            strStack.pop();
            inOrder.push_back(num);
        }
    }
}

int flag = 0;

void visitTree(node *root)
{
	if (root == NULL) return;
    visitTree(root->left);
    visitTree(root->right);
	if (flag == 0)
	{
		flag = 1;
		cout << root->data;
	}
    else
    {
        cout << " " << root->data;
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    initOrder(n);
    node *root = buildTree(0, 0, n - 1);
    visitTree(root);
    return 0;
}