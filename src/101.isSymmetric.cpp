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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
        	return true;
        }
        return isSameTree(root->left, root->right);
    }

    bool isSameTree(TreeNode* n1, TreeNode* n2) {
    	if (n1 == NULL) {
    		return n2 == NULL;
    	}
    	if (n2 == NULL) {
    		return n1 == NULL;
    	}
    	return ((n1->val == n2->val) && isSameTree(n1->left, n2->right) && isSameTree(n1->right, n2->left));
    }
};