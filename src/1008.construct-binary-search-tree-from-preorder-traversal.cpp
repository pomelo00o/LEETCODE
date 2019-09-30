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
    TreeNode* bstFromPreorder(vector<int>& preorder, int bound = INT_MAX) {
        if (i == preorder.size() || preorder[i] > bound) return nullptr;
        TreeNode* node = new TreeNode(preorder[i ++]);
        node->left = bstFromPreorder(preorder, node->val);
        node->right = bstFromPreorder(preorder, bound);
        return node;
    }
};

