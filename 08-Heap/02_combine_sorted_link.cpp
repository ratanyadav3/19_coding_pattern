 

#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;

    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};



//Optimal approach

ListNode* mergeLinkList(vector<ListNode*>lists)
{
    priority_queue<pair<int, ListNode*>,
        vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

    for(int i = 0; i<lists.size(); i++)
    {
        if(lists[i])
        {
            pq.push({lists[i]->data ,lists[i]});
        }
    }

    ListNode* head = new ListNode(-1);
    ListNode* curr = head;
    while(!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        curr->next = it.second;
        curr = curr->next;
        if(it.second->next != NULL)
        {
            pq.push({it.second->next->data , it.second->next});
        }

    }
    return head->next;
}