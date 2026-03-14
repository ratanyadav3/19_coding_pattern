#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* lowestCommonBST(TreeNode* root , TreeNode* p , TreeNode* q)
{
	if(!root)return NULL;

	if(root->val==p->val || root->val==q->val) return root;

	if((p->val<root->val && q->val>root->val)|| (q->val<root->val && p->val>root->val)) return root;

	if((p->val<root->val)||(q->val<root->val))
		return lowestCommonBST(root->left,p,q);
	else
		return lowestCommonBST(root->right,p,q);
}