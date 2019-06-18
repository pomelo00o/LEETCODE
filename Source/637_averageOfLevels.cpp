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
    vector<double> averageOfLevels(TreeNode* root) {
    	vector<double> result;
        vector<vector<double>> temp_result;
    	queue<TreeNode*> q;
        if (root == NULL) {
    		return result;
    	}
    	q.push(root);
    	q.push(NULL);
    	vector<double> temp;
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
    			temp_result.push_back(temp);
                temp.resize(0);
                if (q.size() > 0) {
                    q.push(NULL);
                }
    		}
    	}
    	auto size = temp_result.size();
    	for (auto i = 0; i < size; ++i) {
    		auto temp_size = temp_result[i].size();
    		double sum = 0;
    		for (auto j = 0; j < temp_size; ++j) {
    			sum += temp_result[i][j];
    		}
    		result.push_back(sum / temp_size);
    	}
    	return result;
    }
};