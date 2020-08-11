#include <iostream>

using namespace std;

typedef int elementType;

typedef struct lnode
{
    elementType data;

    struct lnode *next;

} Lnode, *LinkList;

int main()
{
    int n, t = 0;
    cin >> n;

    LinkList root, p;
    root = p = (LinkList)malloc(sizeof(Lnode));

    for (int i = 0; i < n; ++i)
    {
        p->next = (LinkList)malloc(sizeof(Lnode));
        p = p->next;

        cin >> p->data;
        p->next = NULL;
    }

    Lnode *node = (LinkList)malloc(sizeof(Lnode));
    cin >> node->data;
    node->next = NULL;

    p = root;

    while (p != NULL)
    {
        if (t == 0)
        {
            if (p->next == NULL || p->next->data > node->data)
            {
                node->next = p->next;
                p->next = node;
                t = 1;
            }
        }
        if (p != root)
            cout << " " << p->data;
        p = p->next;
    }

    return 0;
}