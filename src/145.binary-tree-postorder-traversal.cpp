/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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

// recursive
// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> res;
//         postorder(root, res);
//         return res;
//     }

//     void postorder(TreeNode* root, vector<int>& res) {
//         if (!root) return;
//         postorder(root->left, res);
//         postorder(root->right, res);
//         res.push_back(root->val);
//     }
// };

// iterative
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* last = nullptr;
        if (!root) return res;
        while (root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root->left;
            } else {
                TreeNode* curr = stk.top();
                if (curr->right && curr->right != last) {
                    root = curr->right;
                } else {
                    res.push_back(curr->val);
                    last = curr;
                    stk.pop();
                }
            }
        }
        return res;
    }

};

