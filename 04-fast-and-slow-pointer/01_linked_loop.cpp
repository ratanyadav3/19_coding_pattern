//Problem statement: Given a linked list, determine if it has a cycle in it.
//A cycle occurs when a node's next pointer points to a previous node in the list.      
//problem link: https://leetcode.com/problems/linked-list-cycle/ , https://bytebytego.com/exercises/coding-patterns/fast-and-slow-pointers/linked-list-cycle    


// In this approach I am not using fast and slow pointer..
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

bool Link_loop(Node* head)
{
    Node* temp = head;
    set<Node*>add;
    while(temp)
    {
        if(add.find(temp)!=add.end())
        {
            return false;

        }
        add.insert(temp);
        temp = temp->next;
    }
    return false;

}