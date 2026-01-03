//problem statement: Given a singly linked list, determine if it is a palindrome.
//problem link: https://www.bytebytego.com/coding/palindromic-linked-list/ ,  https://leetcode.com/problems/palindrome-linked-list/

//Example:
//Input: 1 -> 2 -> 3 -> 2 -> 1
//Output: true

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};


bool palindrome(Node* head)
{
    vector<int>vv;
    Node* curr;
    curr = head;
    while(curr)
    {
        vv.push_back(curr->data);
        curr = curr->next;
    }

    int l = 0;
    int r = vv.size()-1;
    while(l<=r)
    {
        if(vv[l]!=vv[r])
        return false;
        l++;
        r--;
    }
    return true;

}