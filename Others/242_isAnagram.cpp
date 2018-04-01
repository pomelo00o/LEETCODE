class Solution {
public:
    bool isAnagram(string s, string t) {
    	if (s.length() != t.length()) {
    		return false;
    	}
    	auto len = s.length();
        unordered_map<char, int> count;
        for (auto i = 0; i < len; ++i) {
        	count[s[i]]++;
        	count[t[i]]--;
        }
        for (auto cnt : count) {
        	if (cnt.second != 0) {
        		return false;
        	}
        }
        return true;
    }
};