
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode* node)
{
    if(node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}

bool isBalancedUtil(TreeNode* root, int& height)
{
    if(root == NULL)
    {
        height = 0;
        return true;
    }

    int leftHeight = 0, rightHeight = 0;

    bool leftBalanced = isBalancedUtil(root->left, leftHeight);
    bool rightBalanced = isBalancedUtil(root->right, rightHeight);

    height = max(leftHeight, rightHeight) + 1;

    if(abs(leftHeight - rightHeight) > 1)
        return false;

    return leftBalanced && rightBalanced;
}