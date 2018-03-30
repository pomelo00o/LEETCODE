// Time limit exceeded 
class Solution {
public:
    string longestPalindrome(string s) {
    	string t = reverseString(s);
    	string ans = findCommonSubString(s, t);
    	return ans;
    }

    string reverseString(string s) {
    	string str(s.rbegin(),s.rend());
        return str;
    }

    string findCommonSubString(string s, string t) {
    	auto len = s.length();
    	if (len == 0) {
    		return "";
    	}
    	auto target_len = len;
    	while (true) {
    		for (auto i = 0; i < len - target_len + 1; ++i) {
    			auto temp = s.substr(i, target_len);
    			std::size_t found = t.find(temp);
  				if (found!=std::string::npos) {
  					if (!checkPalindrome(temp)) {
    					return temp;
    				}
  				}
    		}
            target_len--;
    	}
    }

    bool checkPalindrome(string s) {
    	auto len = s.length();
    	bool neg = false;
    	for (auto i = 0; i < len; ++i) {
    		if (s[i] != s[len - i - 1]) {
    			neg = true;
    			break;
    		}
    	}
    	return neg;
    }
};