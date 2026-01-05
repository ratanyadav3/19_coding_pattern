//problem statement: Given the head of a singly linked list, return the middle node of the linked list.
//If there are two middle nodes, return the second middle node.
//problem link: https://leetcode.com/problems/middle-of-the-linked-list/ , https://bytebytego.com/exercises/coding-patterns/fast-and-slow-pointers/middle-of-the-linked-list


#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* mid(Node* head)
{
    Node* first = head;
    Node* second = head;

    while(second)
    {
        first = first->next;
        second = second->next->next;
    }
    return first;
}