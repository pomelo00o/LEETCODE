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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> mp;
        queue<pair<int, TreeNode*>> q;
        vector<vector<int>> res;
        if (root) q.push(make_pair(0, root));
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            mp[p.first].push_back(p.second->val);
            if (p.second->left) {
                q.push(make_pair(p.first - 1, p.second->left));
            }
            if (p.second->right) {
                q.push(make_pair(p.first + 1, p.second->right));
            }
        }
        for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
            res.push_back(iter->second);
        }
        return res;
    }
};