#include <iostream>
#include <vector>

using namespace std;

typedef struct node
{
    int m;
    struct node *next;
} node;

int main()
{
    node root1, root2, *p, *q;
    root1.next = root2.next = NULL;
    int n;

    p = &root1;
    while (cin >> n)
    {
        if (n == -1)
            break;
        p->next = (node *)malloc(sizeof(node));
        p->next->m = n;
        p->next->next = NULL;
        p = p->next;
    }
    p = &root2;
    while (cin >> n)
    {
        if (n == -1)
            break;
        p->next = (node *)malloc(sizeof(node));
        p->next->m = n;
        p->next->next = NULL;
        p = p->next;
    }

    p = root1.next;
    q = root2.next;

    int flag = 0;

    while (p)
    {
        int a = p->m;

        if (q == NULL)
            break;

        while (a > q->m)
        {
            q = q->next;
        }
        if (a == q->m)
        {
            if (flag == 0)
            {
                cout << a;
                flag = 1;
            }
            else
                cout << " " << a;
            q = q->next;
        }

        p = p->next;
    }

    if (flag == 0)
        cout << "NULL";
    return 0;
}