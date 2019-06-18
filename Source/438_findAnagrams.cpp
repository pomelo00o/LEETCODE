class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        auto len_p = p.length();
        auto len_s = s.length();
        vector<int> result;
        if (len_s < len_p) {
            return result;
        }
        auto start_index = 0;
        string temp;
        while (start_index <= (len_s - len_p)) {
        	temp = s.substr(start_index, len_p);
        	if (isAnagram(temp, p)) {
        		result.push_back(start_index);
        	}
        	start_index++;
        }
        return result;
    }

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