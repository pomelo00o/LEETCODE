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
        return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) {
        if (ps > pe || is > ie) return nullptr;
        TreeNode* n = new TreeNode(preorder[ps]);
        int pos = 0;
        for (int i = is; i <= ie; ++i) {
            if (n->val == inorder[i]) {
                pos = i;
                break;
            }
        }
        // in the inorder vector, [is, pos - 1] belongs to the left subtree, [pos + 1, ie] belongs to the right subtree,
        // which means (pos - ie) nodes in the left subtree and (ie - pos) nodes in the right subtree
        // in order to keep the node number constant, in the preorder vector, [ps + 1, ps + pos - is] belongs to the left subtree, [pe - ie + pos + 1, pe] belongs to the right subtree
        n->left = helper(preorder, inorder, ps + 1, ps + pos - is, is, pos - 1);
        n->right = helper(preorder, inorder, pe - ie + pos + 1, pe, pos + 1, ie);
        return n;
    }
};

