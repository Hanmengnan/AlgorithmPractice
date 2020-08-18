#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct node
{
    int data;
    struct node *left, *right;
    node(int x) : data(x), left(NULL), right(NULL) {}
} node;

vector<int> nodeVec;

node *insertNode(node *root, int newNode)
{
    if (root == NULL)
    {
        return new node(newNode);
    }
    else
    {
        if (newNode > root->data)
        {
            root->left = insertNode(root->left, newNode);
        }
        else
        {
            root->right = insertNode(root->right, newNode);
        }
        return root;
    }
}

bool printTree(node *root)
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
                if (flag == 2)
                    flag = 3;
                cout << " " << t->data;
            }
			nodeQ.push(t->left);
			nodeQ.push(t->right);

        }
        else if(flag!=3)
        {
            flag = 2;   
        }
    }

    if (flag == 3)
        return true;
    else
        return false;
}

int main()
{
    int n, t;
    cin >> n;
    node *root = NULL;

    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        root = insertNode(root, t);
    }

    if (printTree(root))
        cout << endl
             << "NO";
    else
        cout << endl
             << "YES";

    return 0;
}