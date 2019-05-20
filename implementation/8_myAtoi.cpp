class Solution {
public:
    int myAtoi(string str) {
		if (str.empty()) {
			return 0;
		}
		int sign = 1, base = 0, i = 0, n = str.size();
		while (i < n && str[i] == ' ') {
			++i;
		}
		switch (str[i])
		{
			case '+':
				sign = 1;
                ++i;
				break;
			case '-':
				sign = -1;
                ++i;
				break;
			default:
                sign = 1;
				break;
		}
		while (i < n && str[i] >= '0' && str[i] <= '9') {
			if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            } // in case of overflow
			base = base * 10 + (str[i] - '0');
			++i;
		}
		return base * sign;
    }
};