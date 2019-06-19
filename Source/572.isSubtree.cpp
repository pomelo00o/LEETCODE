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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL) {
        	return false;
        }
        if (isSameTree(s, t)) {
        	return true;
        }
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }

    bool isSameTree(TreeNode* n1, TreeNode* n2) {
    	if (n1 == NULL && n2 == NULL) {
    		return true;
    	}
    	if (n1 == NULL || n2 == NULL) {
    		return false;
    	}
    	return (n1->val == n2->val) && isSameTree(n1->left, n2->left) && isSameTree(n1->right, n2->right);
    }
};