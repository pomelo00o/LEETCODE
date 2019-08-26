/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
 */
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
private:
    int i = 0;
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, INT_MAX);
    }

    TreeNode* helper(vector<int>& preorder, int bound) {
        if (i == preorder.size() || preorder[i] > bound) return nullptr;
        TreeNode* root = new TreeNode(preorder[i++]);
        // left nodes < root
        root->left = helper(preorder, root->val);
        // right nodes > root
        root->right = helper(preorder, bound);
        return root;
    }
};

