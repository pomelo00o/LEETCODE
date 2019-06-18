/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
    	vector<int> vec;
    	vec.clear();
    	while (head != NULL) {
    		vec.push_back(head->val);
    		head = head->next;
    	}
    	vector<int> reverse_vec;
    	vector<int>::reverse_iterator reverse_iter;
    	for (reverse_iter=vec.rbegin(); reverse_iter!=vec.rend(); ++reverse_iter) {
        	reverse_vec.push_back(*reverse_iter);
    	}
    	return vec_cmp(vec, reverse_vec);
    }

    bool vec_cmp(vector<int> vec, vector<int> reverse_vec) {
    	auto len = vec.size();
    	for (auto i = 0; i < len; ++i) {
    		if (vec[i] != reverse_vec[i]) {
    			return false;
    		}
    	}
    	return true;
    }
};