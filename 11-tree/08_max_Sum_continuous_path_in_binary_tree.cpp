#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

int ans = INT_MIN;

int maxSum(TreeNode* root)
{
    if(root==NULL) return 0;

    int left = maxSum(root->left);
    int right = maxSum(root->right);

    ans = max(ans , root->val+left+right);

    return max(0 , root->val + max(left,right));
}

int main()
{
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val=1;
    root->left = (TreeNode*)malloc(sizeof(TreeNode));
    root->left->val=2;
    root->right = (TreeNode*)malloc(sizeof(TreeNode));
    root->right->val=3;

    maxSum(root);

    cout<<ans<<endl;

    return 0;
}