class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        auto len = s.length();
        for (auto i = 0; i < len; ++i) {
        	if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
        		stk.push(s[i]);
        	}
        	if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
        		if (stk.empty() == true) {
        			return false;
        		}
        		auto ch = stk.top();
        		if ((s[i] == ')' && ch == '(') || (s[i] == ']' && ch == '[') || (s[i] == '}' && ch == '{')) {
        			stk.pop();
        		} else {
        			return false;
        		}
        	}
        }
        return stk.empty();
    }
};