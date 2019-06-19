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
    int longestUnivaluePath(TreeNode* root) {
        if (root == NULL) {
        	return 0;
        }
        int longestPath = 0;
        helper(root, longestPath);
        return longestPath;
    }

    int helper(TreeNode* root, int& m){
        int l=root->left ? helper(root->left, m) : 0;
        int r=root->right ? helper(root->right, m) : 0;
        l = (root->left && root->left->val == root->val) ? l + 1 : 0;
        r = (root->right && root->right->val == root->val) ? r + 1 : 0;
        m = max(m,l + r);
        return max(l, r);
    }
};