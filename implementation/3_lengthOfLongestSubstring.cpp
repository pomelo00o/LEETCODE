class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vec(256, -1);
    	int maxLen = 0, start = -1;  
    	for (int i = 0; i != s.length(); i++) {  
			start = max(vec(s[i]), start)
        	vec[s[i]] = i;  
        	maxLen = max(maxLen, i - start);  
    	}
    	return maxLen;
    }
};