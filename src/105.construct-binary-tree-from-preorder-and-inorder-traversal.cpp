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
    // in the inorder vector, [is, pos - 1] belongs to the left subtree, [pos + 1, ie] belongs to the right subtree,
    // which means (pos - is) nodes in the left subtree and (ie - pos) nodes in the right subtree
    // in order to keep the node number constant, in the preorder vector, [ps + 1, ps + pos - is] belongs to the left subtree, [pe - ie + pos + 1, pe] belongs to the right subtree
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return pre_in(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* pre_in(vector<int>& pre, vector<int>& in, int ps, int pe, int is, int ie) {
        if (ps > pe || is > ie) return nullptr;
        TreeNode* node = new TreeNode(pre[ps]);
        int pos = 0;
        for (int i = is; i <= ie; ++i) {
            if (in[i] == node->val) {
                pos = i;
                break;
            }
        }
        node->left = pre_in(pre, in, ps + 1, ps + pos - is, is, pos - 1);
        node->right = pre_in(pre, in, pe + pos - ie + 1, pe, pos + 1, ie);
        return node;
    }
};

