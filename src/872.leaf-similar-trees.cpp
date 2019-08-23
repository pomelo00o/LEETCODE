/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
    // basic idea is to do a dfs
    // visit(left) --> visit(right)
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1, s2;
        dfs(root1, s1);
        dfs(root2, s2);
        return s1 == s2;
    }

    void dfs(TreeNode* n, string& s) {
        if (!n) return;
        if (!(n->left) && !(n->right)) {
            s += '@' + to_string(n->val);
            // @ is used to distinguish (1, 2, 3) from (12, 3)
            return;
        }
        dfs(n->left, s);
        dfs(n->right, s);
    }
};

