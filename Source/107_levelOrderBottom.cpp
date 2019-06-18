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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
    	queue<TreeNode*> q;
        if (root == NULL) {
    		return result;
    	}
    	q.push(root);
    	q.push(NULL);
    	vector<int> temp;
    	while (q.empty() == false) {
    		auto node = q.front();
    		q.pop();
    		if (node != NULL) {
    			temp.push_back(node->val);
    			if (node->left != NULL) {
    				q.push(node->left);
    			}
    			if (node->right != NULL) {
    				q.push(node->right);
    			}
    		} else {
    			result.push_back(temp);
                temp.resize(0);
                if (q.size() > 0) {
                    q.push(NULL);
                }
    		}
    	}
    	reverse(result.begin(), result.end());
    	return result;
    }
};