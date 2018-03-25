// Correct during running, but error during submission
class Solution {
public:
    int myAtoi(string str) {
        if (str[1] == '+' || str[1] == '-') {
            return 0;
        }
        if (str[0] == '0') {
            str.erase(str.begin());
        }
    	bool sign = false;
    	if (str[0] == '-' || str[0] == '+') {
    		sign = true;
    	}
    	bool positive = true;
    	if (str[0] == '-') {
    		positive = false;
    	}
        auto flag = (positive == true) ? 1 : -1;
    	string reverse_str;
    	if (sign == true) {
    		str.erase(str.begin());
    		for (auto iter = str.rbegin(); iter != str.rend(); ++iter) {
    			reverse_str.push_back(*iter);
    		}
    	} else {
        	for (auto iter = str.rbegin(); iter != str.rend(); ++iter) {
    			reverse_str.push_back(*iter);
    		}
        }
        int64_t sum = 0;
        auto len = str.size();
        auto i = 0;
        while (i < len) {
        	sum += (reverse_str[i] - '0') * std::pow(10, i);
        	i++;
        	if (flag * sum > INT_MAX) {
        		return INT_MAX;
        	}
        	if (flag * sum < INT_MIN) {
        		return INT_MIN;
        	}
        }
        return (int32_t)(flag * sum);
    }
};