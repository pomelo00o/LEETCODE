/*
 * @lc app=leetcode id=889 lang=cpp
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return helper(pre, post, 0, pre.size() - 1, 0, post.size() - 1);
    }

    TreeNode* helper(vector<int>& pre, vector<int>& post, int pres, int pree, int posts, int poste) {
        if (pres > pree || posts > poste) return nullptr;
        TreeNode* n = new TreeNode(pre[pres]);
        if (pres == pree) return n;
        int pos = 0;
        for (pos = posts; pos <= poste; ++pos) {
            if (post[pos] == pre[pres + 1]) break;
        }
        // left subtree: len_left = pos - posts + 1
        // right subtree: len_right = poste - posts - len_left = poste - posts - pos + posts - 1 = poste - pos - 1
        n->left = helper(pre, post, pres + 1, pos - posts + 1 + pres, posts, pos);
        n->right = helper(pre, post, pres + 1 + pos - posts + 1, pree, pos + 1, poste - 1);
        return n;
    }
};

