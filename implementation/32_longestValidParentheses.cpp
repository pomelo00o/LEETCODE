class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int start = 0;
        stack<int> m;
        for (int i = 0; i < s.size(); ++i) {
            /*
                if left parentheses, push the current index to stack
            */
            if (s[i] == '(') {
                m.push(i);
            }
            else {
                if (m.empty()) {
                    start = i + 1;
                } else {
                    m.pop();
                    res = m.empty() ? max(res, i - start + 1) : max(res, i - m.top());
                }
            }
        }
        return res;
    }
};