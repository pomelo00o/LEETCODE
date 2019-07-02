/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
// RECURSIVE WAY
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         inorderHelper(root, res);
//         return res;
//     }

//     void inorderHelper(TreeNode* root, vector<int>& res) {
//         if (!root) return;
//         inorderHelper(root->left, res);
//         res.push_back(root->val);
//         inorderHelper(root->right, res);
//     }
// };

// ITERATIVE WAY
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> stk;
        auto curr = root;
        pushLeftNode(curr, stk);
        while (!stk.empty()) {
            auto tmp =  stk.top();
            stk.pop();
            res.push_back(tmp->val);
            pushLeftNode(tmp->right, stk);
        }
        return res;
    }

    void pushLeftNode(TreeNode* root, stack<TreeNode*>& stk) {
        while (root) {
            stk.push(root);
            root = root->left;
        }
    }
};

