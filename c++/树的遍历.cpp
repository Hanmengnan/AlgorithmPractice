#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct node
{
    int data;
    struct node *left, *right;
    node(int x) : data(x), left(NULL), right(NULL) {}
} node;

vector<int> postOrder;
vector<int> midOrder;

node *buildTree(int aim, int left, int right)
{
    if (left == right)
        return new node(postOrder[aim]);
    else if (left > right)
        return NULL;
    else
    {
        node *root = new node(postOrder[aim]);
        int index = find(midOrder.begin(), midOrder.end(), postOrder[aim]) - midOrder.begin();

        root->left = buildTree(aim - (right - index) - 1, left, index - 1);
        root->right = buildTree(aim - 1, index + 1, right);
        return root;
    }
}

void printTree(node *root)
{
    int flag = 0;
    queue<node *> nodeQ;
    nodeQ.push(root);
    while (!nodeQ.empty())
    {
        node *t = nodeQ.front();
        nodeQ.pop();
        if (t != NULL)
        {
            if (flag == 0)
            {
                flag = 1;
                cout << t->data;
            }
            else
            {
                cout << " " << t->data;
            }
            nodeQ.push(t->left);
            nodeQ.push(t->right);
        }
    }
}

int main()
{
    int n, t;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        postOrder.push_back(t);
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        midOrder.push_back(t);
    }
    node *root = buildTree(n - 1, 0, n - 1);

    printTree(root);

    return 0;
}