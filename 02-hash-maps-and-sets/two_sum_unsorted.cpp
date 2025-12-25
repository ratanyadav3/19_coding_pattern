// problem statement: Given an unsorted array of integers, find all pairs of elements that sum up to a specific target value using hashing.
//link: https://www.codingninjas.com/codestudio/problems/two-sum_8230713?challengeSlug=striver-sde-challenge  , https://bytebytego.com/exercises/coding-patterns/hash-maps-and-sets/pair-sum-unsorted


#include<bits/stdc++.h>
using namespace std;

void pairSumHashing(int arr[], int n, int target)
{
    unordered_map<int,int>m;
    for(int i=0;i<n;i++)
    {
        int complement = target - arr[i];
        if(m.find(complement) != m.end())
        {
            cout<<"Values ("<<arr[i]<<","<<complement<<") Index ("<< m[complement] <<","<<i<<")"<<endl;
        }
        m[arr[i]]=i;
    }
}
int main() {
    int arr[] = {10, 2, 3, 5, 7, 8};
    int target = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    pairSumHashing(arr, n, target);
    return 0;
}