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
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) {
        	return 0;
        }
        return isValid(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int isValid(TreeNode* root, int pre, int sum) {
    	if (root == NULL) {
    		return 0;
    	}
    	auto current = pre + root->val;
        return (current == sum) + isValid(root->left, current, sum) + isValid(root->right, current, sum);
    }
};