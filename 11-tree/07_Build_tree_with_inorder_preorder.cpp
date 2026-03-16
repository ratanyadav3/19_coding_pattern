#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* buildTree(vector<int>&preorder , vector<int>&inorder)
{
	map<int,int>inMap;
	for(int i =0; i<inorder.size(); i++)
	{
		inMap[inorder[i]]=i;
	}

	TreeNode* root = buildTree(preorder , 0 , preorder.size()-1 , inorder , 0 , inorder.size()-1,inMap);

	return root;
}

TreeNode* buildTree( vector<int>&preorder , int preStart , int preEnd , vector<int>&inorder, int inStart , int inEnd, map<int,int>inMap)
{
	if(preStart>preEnd || inStart>inEnd) return NULL;

	TreeNode * root = (TreeNode*)malloc(sizeof(TreeNode));
	root->val=preorder[preStart];

	int intRoot = inMap[root->val];
	int numsLeft  = intRoot-inStart;


	root->left = buildTree(preorder,preStart+1,preStart+numsLeft, inorder , inStart,intRoot-1,inMap);
	root->right = buildTree(preorder,preStart+numsLeft+1,preEnd , inorder,numsLeft+1,inEnd , inMap);

	return root;
}