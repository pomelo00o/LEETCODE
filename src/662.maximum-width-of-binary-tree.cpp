/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        vector<TreeNode*> vec;
        vec.push_back(root);
        int res = 1;
        while (!vec.empty()) {
            vector<TreeNode*> next;
            next.clear();
            for (int i = 0; i < vec.size(); ++i) {
                auto node = vec[i];
                if (!node) {
                    next.push_back(nullptr);
                    next.push_back(nullptr);
                } else {
                    next.push_back(node->left);
                    next.push_back(node->right);
                }
            }
            next = valid(next);
            res = max(res, (int)(next.size()));
            vec.assign(next.begin(), next.end());
        }
        return res;
    }

    vector<TreeNode*> valid(vector<TreeNode*>& next) {
        vector<TreeNode*> n;
        if (next.empty()) return n;
        int left = 0;
        int right = next.size() - 1;
        while (left <= right && !next[left]) 
            left += 1;
        while (left <= right && !next[right]) 
            right -= 1;
        for (int i = left; i <= right; ++i) {
            auto tmp = next[i];
            n.push_back(tmp);
        }
        return n;
    }
};

