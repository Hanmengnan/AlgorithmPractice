#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <regex>
#include <algorithm>
#include <math.h>

using namespace std;

typedef struct node
{
    int data, height;
    struct node *left, *right, *parent;
    node(int x, int h, node *p) : data(x), height(h), left(NULL), right(NULL), parent(p) {}
} node;

node *insertNode(node *root, node *pa, int newNode, int h)
{
    if (root == NULL)
    {
        return new node(newNode, h + 1, pa);
    }
    else
    {
        if (newNode < root->data)
        {
            root->left = insertNode(root->left, root, newNode, h + 1);
        }
        else
        {
            root->right = insertNode(root->right, root, newNode, h + 1);
        }
        return root;
    }
}

node *Search(node *T, int k)
{
    node *p = T;
    while (p)
    {
        if (p->data > k)
            p = p->left;
        else if (p->data < k)
            p = p->right;
        else
            return p;
    }
    return NULL;
}

int main()
{
    regex p1("([0-9]*) is the root");
    regex p2("([0-9]*) and ([0-9]*) are siblings");
    regex p3("([0-9]*) is the parent of ([0-9]*)");
    regex p4("([0-9]*) is the left child of ([0-9]*)");
    regex p5("([0-9]*) is the right child of ([0-9]*)");
    regex p6("([0-9]*) and ([0-9]*) are on the same level");

    int n, t;
    cin >> n;
    node *root = NULL;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        root = insertNode(root, root, t, 0);
    }

    cin >> n;
    getchar();
    string str;
    str.resize(999);
    smatch res;
    for (int i = 0; i < n; ++i)
    {
        getline(cin, str);

        if (regex_match(str, res, p1))
        {
            int num = atoi(string(res[1]).c_str());

            node *r = Search(root, num);

            if (r == NULL)
                cout << "No" << endl;

            else if (r->height == 1)
                cout
                    << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else if (regex_match(str, res, p2))
        {
            int num1 = atoi(string(res[1]).c_str());
            int num2 = atoi(string(res[2]).c_str());

            node *r1 = Search(root, num1), *r2 = Search(root, num2);
            if (r1 == NULL || r2 == NULL)
                cout << "No" << endl;

            else if (r1->parent == r2->parent)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else if (regex_match(str, res, p3))
        {
            int num1 = atoi(string(res[1]).c_str());
            int num2 = atoi(string(res[2]).c_str());

            node *r1 = Search(root, num1), *r2 = Search(root, num2);
            if (r1 == NULL || r2 == NULL)
                cout << "No" << endl;

            else if (r2->parent == r1)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else if (regex_match(str, res, p4))
        {
            int num1 = atoi(string(res[1]).c_str());
            int num2 = atoi(string(res[2]).c_str());

            node *r1 = Search(root, num1), *r2 = Search(root, num2);
            if (r1 == NULL || r2 == NULL)
                cout << "No" << endl;

            else if (r1 == r2->left)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else if (regex_match(str, res, p5))
        {
            int num1 = atoi(string(res[1]).c_str());
            int num2 = atoi(string(res[2]).c_str());

            node *r1 = Search(root, num1), *r2 = Search(root, num2);
            if (r1 == NULL || r2 == NULL)
                cout << "No" << endl;
            else if (r1 == r2->right)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else if (regex_match(str, res, p6))
        {
            int num1 = atoi(string(res[1]).c_str());
            int num2 = atoi(string(res[2]).c_str());

            node *r1 = Search(root, num1), *r2 = Search(root, num2);
            if (r1 == NULL || r2 == NULL)
                cout << "No" << endl;

            else if (r1->height == r2->height)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}
