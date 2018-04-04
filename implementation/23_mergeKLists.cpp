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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	vector<int> allValue;
        auto vec_size = lists.size();
        for (auto i = 0; i < vec_size; ++i) {
        	auto vec = listValue(lists[i]);
        	auto len = vec.size();
        	for (auto j = 0; j < len; ++j) {
        		allValue.push_back(vec[j]);
        	}
        }
        std::sort(allValue.begin(), allValue.end(), cmp_node);
        auto num = allValue.size();
        vector<ListNode*> Node(num, NULL);
        for (auto i = 0; i < num; ++i) {
        	Node.push_back(createNewNode(allValue[i]));
        }
        for (auto i = 0; i < num - 1; ++i) {
        	Node[i]->next = Node[i + 1];
        }
        return Node[0];
    }

	static bool cmp_node(const ListNode* l1, const ListNode* l2) {
    	return l1->val < l2->val;
    }
    
    ListNode* createNewNode(int v) {
    	ListNode* temp;
    	temp->val = v;
    	temp->next = NULL;
        return temp;
    }

    vector<int> listValue(ListNode* head) {
    	vector<int> vec;
    	ListNode* curr = head;
    	while (curr != NULL) {
    		vec.push_back(curr->val);
    		curr = curr->next;
    	}
    	return vec;
    }
};