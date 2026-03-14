#include<bits/stdc++.h>.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

//using min-max range 
//solving using recursion

bool isValidBST(TreeNode* root, long long minVal = LLONG_MIN, long long maxVal = LLONG_MAX)
{
    if(!root)return true;

    if(root->val<=minVal || root->val>=maxVal)
    return false;

    return(isValidBST(root->left , minVal , root->val) && isValidBST(root->right, root->val , maxVal));
}