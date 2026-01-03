// problem statement: Given a multi-level linked list where in addition to the next pointer, each node has a child pointer, which may or may not point to a separate list. These child lists may have one or more children of their own, and so on, to produce a multi-level data structure. Flatten the list so that all the nodes appear in a single-level, using the next pointers.

//problem link: https://www.bytebytego.com/coding/flat-multi-level-linked-list/

//Example:
//Input:
// 1 - 2 - 3 - 4 - 5 - 6
//         |
//         7 - 8 - 9 - 10
//             |
//             11 - 12      

//output:
//1 - 2 - 3 - 4 - 5 - 6 - 7 - 8 - 9 - 10 - 11 - 12



#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *child;
};

Node *flat(Node *head)
{
    queue<Node *> q;
    Node *curr;
    curr = head;
    while (curr)
    {
        if (curr->child != NULL)
        {
            q.push(curr->child);
            curr->child = NULL;
        }
        if (curr->next == NULL)
        {
            curr->next = q.front();
            q.pop();
        }
        curr = curr->next;
    }
    return head;
}
