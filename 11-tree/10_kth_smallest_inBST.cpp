#include<bits/stdc++.h>
using  namespace std; 


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};



int kthSmallest(TreeNode* root, int k) {
    if(root==NULL) return -1;

    int left = kthSmallest(root->left,k);
    if(left!=-1) return left;

    k--;
    if(k==0) return root->val;

    return kthSmallest(root->right,k);
}

int main()
{
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = 3;
    root->left = (TreeNode*)malloc(sizeof(TreeNode));
    root->left->val = 1;
    root->left->left = NULL;
    root->left->right = (TreeNode*)malloc(sizeof(TreeNode));
    root->left->right->val = 2;
    root->left->right->left = NULL;
    root->left->right->right = NULL;

    root->right = (TreeNode*)malloc(sizeof(TreeNode));
    root->right->val = 4;
    root->right->left = NULL;
    root->right->right = NULL;

    cout<<kthSmallest(root,1)<<endl;

    return 0;
}