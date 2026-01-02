// Reverse a linked list
//link: https://leetcode.com/problems/reverse-linked-list/description/ , https://bytebytego.com/exercises/coding-patterns/linked-lists/reverse-a-linked-list


#include<bits/stdc++.h>
using namespace std; 
struct Node{
    int data;
    Node *next;
};
Node* rev(Node *head)
{
    if(!head || !head->next)
    {
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *next_node = NULL;
    while(curr)
    {
        next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }

    return prev;

}
