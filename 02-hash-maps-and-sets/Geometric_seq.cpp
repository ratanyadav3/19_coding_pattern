//problem statement : Given an array of integers and a common ratio r, find the number of triplets (i, j, k) such that i < j < k and arr[j] = arr[i] * r and arr[k] = arr[j] * r
//problem link : https://www.hackerrank.com/challenges/count-triplets-1 , https://bytebytego.com/exercises/coding-patterns/hash-maps-and-sets/geometric-sequence-triplets



//logic : Geometric sequence Triplet [first , first*r , (first*r)*r];

// ex :arr= [2 , 1 , 2 , 4 , 8 , 8] , r=2
//valid triplet = (2,4,8) , (1,2,4) , (2,4,8) , (2,4,8) and (1,2,4) => total 5 triplet
//approach : we will use two hash maps left and right because we need to keep track of elements on both sides of current element 
// left will store the count of elements to the left of current element
// right will store the count of elements to the right of current element
// we will iterate through the array and for each element we will check if there exists a triplet
// if yes we will add the count of such triplets to the answer 

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; //size of the array
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }   
    int r ; //common ratio
    cin>>r;
    unordered_map<int,int>left, right;
    for(int i=0; i<n; i++)
    {
        right[arr[i]]++;
    }
    int count =0;
    for(int i=0;i<n; i++)
    {
        right[arr[i]]--;
        int num = arr[i]; //mid element 
        if(r!=0 && num%r==0) //checking geometric triplet 
        {
            count += left[num/r]*right[num*r];
        }
        left[num]++;
    }
    cout<<count;
    return 0;
}