// Correct during running, but error during submission
class Solution {
public:
    int myAtoi(string str) {
        auto index = str.find_first_not_of(' ');
        if (index == string::npos) {
        	return 0;
        }
        long result = 0;
        bool negative = false;
       	if (str[index] == '-') {
       		negative = true;
       		index++;
        } else if (str[index] == '+') {
            index++;
        }
        else {
			// do nothing
        }
       	auto len = str.length();
       	for (auto i = index; i < len; ++i) {
       		if (isdigit(str[i])) {
       			result = result * 10 + (str[i] - '0');
       			if (negative && -result <= INT_MIN) {
       				return INT_MIN;
       			}
       			if (!negative && result >= INT_MAX) {
       				return INT_MAX;
       			}
       		} else {
       			break;
       		}
       	}
       	if (negative) {
       		return int(-result);
       	}
       	return int(result);
    }
};