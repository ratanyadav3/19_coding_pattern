//This is not optimal approach but a brute force approach to merge k sorted linked lists    
//I will optimize it using priority queue in next code


#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;
};

ListNode* mergeList(vector<ListNode*>lists)
{
    ListNode* temp ;
    vector<int>res;
    for(int i =0; i<lists.size(); i++)
    {
        temp = lists[i];
        while(temp!=NULL)
        {
            res.push_back(temp->data);
            temp = temp->next;
        }
    }
    sort(res.begin(), res.end());
    ListNode* head = new ListNode();
    ListNode* curr = head;
    for(int i =0; i<res.size(); i++)
    {
        ListNode* newListNode = new ListNode();
        newListNode->data = res[i];
        curr->next = newListNode;
        curr = curr->next;  
    }
    return head->next;   
}