#include <iostream>
#include <vector>
using namespace std;

typedef struct node
{
    int m;
    struct node *next;
    node() : m(0), next(NULL){};
} node;

int main()
{
    int k, n, count = 0;
    scanf("%d", &k);

    node root;
    root.m = 0;
    root.next = NULL;

    node *p = &root, *q = &root;

    while (1)
    {
        scanf("%d", &n);
        if (n < 0)
            break;
        else
        {

            p->next = (node *)malloc(sizeof(node));
            p = p->next;

            p->m = n;
            p->next = NULL;

            if (count > k - 2)
            {
                q = q->next;
            }

            count++;
        }
    }

    if (count < k || k == 0)
    {
        cout << "NULL";
    }
    else
    {
        cout << q->m;
    }
    return 0;
}