//Problem statement: Given a number n, determine if it is a happy number.
//A happy number is defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle that does not include 1. Those numbers for which this process ends in 1 are happy numbers.    

//problm link: https://leetcode.com/problems/happy-number/ , https://bytebytego.com/exercises/coding-patterns/fast-and-slow-pointers/happy-number

//Example 1:
//Input: n = 19
//Output: true
//Explanation:
//1^2 + 9^2 = 82
//8^2 + 2^2 = 68
//6^2 + 8^2 = 100 
//1^2 + 0^2 + 0^2 = 1       



#include<bits/stdc++.h>
using namespace std;

int square_sum(int n)
{
    int d , t=0;
    while(n>0)
    {
         d = n%10;
         t += d*d;
         n  = n/10;
    }
    return t;
}

bool isHappy(int n)
{
    int fast , slow;
    slow = n;
    fast = square_sum(n);
    while(fast!=1 && fast!=slow)
    {
        slow = square_sum(slow);
        fast = square_sum(square_sum(fast));
    }
    if(fast==1)
    return true;

    return false;
}