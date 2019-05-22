class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				stk.push(s[i]);
			} else {
				if (stk.empty()) {
					return false;
				}
				switch (s[i])
				{
				case ')':
					if (stk.top() != '(') {
						return false;
					}
					break;
				case ']':
					if (stk.top() != '[') {
						return false;
					}
					break;
				case '}':
					if (stk.top() != '{') {
						return false;
					}
					break;
				default:
					break;
				}
				stk.pop();
			}
		}
		return stk.empty();
    }
};