//probllem statement:Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
//problem link: https://leetcode.com/problems/intersection-of-two-linked-lists/ , https://

#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
};

Node* interSect(Node* head1, Node* head2)
{
    unordered_set<Node*>link1;
    Node *curr , *temp;
    curr = head1;
    while(curr)
    {
        link1.insert(curr);
        curr = curr->next;
    }
    curr = head2;
    while(curr)
    {
        if(curr == *link1.find(curr))return curr;
        curr = curr->next;
    }
    return curr;
}