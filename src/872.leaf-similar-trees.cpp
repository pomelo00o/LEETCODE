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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string t1, t2;
        DFS(root1, t1);
        DFS(root2, t2);
        return t1 == t2;
    }

    void DFS(TreeNode* root, string& s) {
        if (!root) return;
        if (isLeaf(root)) {
            s += "#" + to_string(root->val);
        } else {
            DFS(root->left, s);
            DFS(root->right, s);
        }
    }

    bool isLeaf(TreeNode* root) {
        return !root->left && !root->right;
    }
};

