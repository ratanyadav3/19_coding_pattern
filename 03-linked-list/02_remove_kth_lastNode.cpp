//problem statement: Given the head of a linked list, remove the k-th last element from the list and return its head.
//problem link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/ ,  https://bytebytego.com/exercises/coding-patterns/linked-lists/remove-the-kth-last-node-from-a-linked-list
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
};

Node* removing(Node* head , int k)
{
    Node *temp = NULL;
    Node *curr , *prev;
    int totalCount=0;
    curr = head;
    while(curr)
    {
        totalCount++;
        curr = curr->next;
    }
    if(totalCount==k)
    {
        return(head->next);
    }
    curr = head;
    int cou = 1;
    while(curr)
    {
        if((totalCount-k+1)==cou)
        {
            prev->next = curr->next;
            break;
        }
        temp = curr->next;
        prev = curr;
        curr = temp;
        cou++;
    }

    return head;
}