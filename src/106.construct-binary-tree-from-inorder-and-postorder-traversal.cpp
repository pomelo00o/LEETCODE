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
        return in_post(inorder, postorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* in_post(vector<int>& in, vector<int>& post, int ps, int pe, int is, int ie) {
        if (ps > pe || is > ie) return nullptr;
        TreeNode* node = new TreeNode(post[pe]);
        int pos = 0;
        for (int i = is; i <= ie; ++i) {
            if (in[i] == node->val) {
                pos = i;
                break;
            }
        }
        node->left = in_post(in, post, ps, ps - 1 - is + pos, is, pos - 1);
        node->right = in_post(in, post, pe + pos - ie, pe - 1, pos + 1, ie);
        return node;
    }
};

