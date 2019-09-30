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
        return pre_post(pre, post, 0, pre.size() - 1, 0, post.size() - 1);
    }

    TreeNode* pre_post(vector<int>& pre, vector<int>& post, int pres, int pree, int posts, int poste) {
        if (pres > pree || posts > poste) return nullptr;
        TreeNode* node = new TreeNode(pre[pres]);
        if (pres == pree) return node;
        int pos = 0;
        for (int i = posts; i <= poste; ++i) {
            if (post[i] == pre[pres + 1]) {
                pos = i;
                break;
            }
        }

        // left subtree: len_left = pos - posts + 1
        // right subtree: len_right = poste - pos - 1
        node->left = pre_post(pre, post, pres + 1, pos - posts + 1 + pres, posts, pos);
        node->right = pre_post(pre, post, pree + pos - poste + 2, pree, pos + 1, poste - 1);
        return node;
    }
};

