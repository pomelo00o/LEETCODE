class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
        	return false;
        }
        if (x == 0) {
        	return true;
        }
        string str = std::to_string(x);
        string reverse_str(str.rbegin(), str.rend());
        return str == reverse_str;
    }
};