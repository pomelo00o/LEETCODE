/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
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
private:
    struct node {
        int x, y, val;
        node(int x1, int y1, int v): x(x1), y(y1), val(v){}
    };
    static bool cmp(node& a, node& b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y) || (a.x == b.x && a.y == b.y && a.val < b.val);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        vector<node> vec;
        inorder(root, 0, 0, vec);
        sort(vec.begin(), vec.end(), cmp);
        int prev_x = vec[0].x;
        res.push_back({vec[0].val});
        for (int i = 1; i < vec.size(); ++i) {
            if (vec[i].x != prev_x) {
                prev_x = vec[i].x;
                res.push_back({vec[i].val});
            } else {
                res.back().push_back(vec[i].val);
            }
        }
        return res;
    }

    void inorder(TreeNode* root, int x, int y, vector<node>& vec) {
        if (!root) return;
        inorder(root->left, x - 1, y + 1, vec);
        vec.push_back(node(x, y, root->val));
        inorder(root->right, x + 1, y + 1, vec);
    }
};

