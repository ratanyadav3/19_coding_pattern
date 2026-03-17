#include<bits/stdc++.h>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

bool isSymmetric(TreeNode* root) {
    if(root==NULL) return true;

    return isSymmetric(root->left,root->right);
}      

bool isSymmetric(TreeNode* a , TreeNode* b)
{
    if(!a && !b) return true;

    if(!a || !b) return false;

    if(a->val!=b->val) return false;

    return isSymmetric(a->left,b->right) && isSymmetric(a->right,b->left);
}