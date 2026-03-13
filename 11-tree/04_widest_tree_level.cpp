#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
	int data;
	TreeNode*left;
	TreeNode*right;
};

int wideLevel(TreeNode* root)
{
	if(root==NULL) return 0;

	queue<pair<TreeNode*,unsigned long long>>q;

	q.push({root,0});
	unsigned long long fst = 0;
	unsigned long long lst = 0;
	unsigned long long ans = 0;

	while(!q.empty())
	{
		int size = q.size();
		unsigned long long minHeight = q.front().second;
		for(int i =0; i<size; i++)
		{
			TreeNode * temp = q.front().first;
			unsigned long long idx = q.front().second-minHeight;

			if(i==0)fst=idx;

			if(i==size-1)lst = idx;

			if(temp->left)q.push({temp->left,2*idx+1});

			if(temp->right)q.push({temp->right,2*idx+2});
		}
		ans = max(ans,lst-fst+1);
	}
	return ans;
}