#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct node
{
    char c;
    struct node *left, *right;
    node(char x) : c(x), left(NULL), right(NULL) {}
} node;

vector<char> pre_list;
vector<char> mid_list;

node *bulit_tree(int p, int left, int right)
{
    if (left > right)
        return NULL;
    else if (left == right)
        return new node(pre_list[p]);
    int index = find(mid_list.begin() + left, mid_list.begin() + right, pre_list[p]) - mid_list.begin();
    node *t = new node(pre_list[p]);
    t->left = bulit_tree(p + 1, left, index - 1);
    t->right = bulit_tree(p + (index - left) + 1, index + 1, right);
    return t;
}

int main()
{
    char c;
    while (c = getchar())
    {
        if (isalpha(c) || isdigit(c))
            pre_list.push_back(c);
        else
            break;
    }
    while (c = getchar())
    {
        if (isalpha(c) || isdigit(c))
            mid_list.push_back(c);
        else
            break;
    }

    node *root = bulit_tree(0, 0, pre_list.size()-1);

    queue<node *> q;

    cout << root->c;
    
    q.push(root->left);
	q.push(root->right);

    while (!q.empty())
    {
        node *t = q.front();
        q.pop();
        if (t != NULL)
        {
            cout << t->c;
            q.push(t->left);
			q.push(t->right);
        }
    }

    return 0;
}