/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int pre_start, int in_start, int in_end) {
        if (pre_start >= preorder.size() || in_start > in_end) return nullptr;
        TreeNode* root = new TreeNode(preorder[pre_start]);
        int in_index = 0;
        for (int i = in_start; i <= in_end; ++i) {
            if (inorder[i] == preorder[pre_start]) {
                in_index = i;
                break;
            }
        }
        root->left = helper(preorder, inorder, pre_start + 1, in_start, in_index - 1);
        root->right = helper(preorder, inorder, pre_start + in_index - in_start + 1, in_index + 1, in_end);
        return root;
    }
};

