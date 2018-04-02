/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int maxDepth = 0;

    int diameterOfBinaryTree(TreeNode* root) {
       	dfs(root);
       	return maxDepth;
    }

    int dfs(TreeNode* root) {
    	if (root == NULL) {
    		return 0;
    	} 
    	auto leftDepth = dfs(root->left);
    	auto rightDepth = dfs(root->right);
    	if ((leftDepth + rightDepth) > maxDepth) {
    		maxDepth = leftDepth + rightDepth;
    	}
    	return max(leftDepth + 1, rightDepth + 1);
    }
};