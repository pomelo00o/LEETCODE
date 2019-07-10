/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, postorder, postorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int ppos, int in_start, int in_end) {
        if (ppos < 0 || in_start > in_end) return nullptr;
        TreeNode* root = new TreeNode(postorder[ppos]);
        int in_idx = 0;
        for (int i = in_start; i <= in_end; ++i) {
            if (inorder[i] == postorder[ppos]) {
                in_idx = i;
                break;
            }
        }
        root->left = helper(inorder, postorder, ppos - 1 - in_end + in_idx, in_start, in_idx - 1);
        root->right = helper(inorder, postorder, ppos - 1, in_idx + 1, in_end);
        return root;
    }
};

