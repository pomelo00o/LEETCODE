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

    TreeNode* helper(vector<int>& pre, vector<int>& post, int s1, int e1, int s2, int e2) {
        if (s1 > e1 || s2 > e2) return nullptr;
        TreeNode* root = new TreeNode(pre[s1]);
        if (s1 == e1) return root;
        int m1 = s1 + 1;
        int m2 = s2;
        int set1 = 0, set2 = 0;
        while (set1 == 0 || set1 != set2) {
            set1 |= 1 << pre[m1++];
            set2 |= 1 << post[m2++];
        }
        root->left = helper(pre, post, s1 + 1, m1 - 1, s2, m2 - 1);
        root->right = helper(pre, post, m1, e1, m2, e2);
        return root;
    }
};

