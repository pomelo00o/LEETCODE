class Solution {
public:
    int divide(int dividend, int divisor) {
    	if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
    		return INT_MAX;
    	}
    	int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
    	long dvd = labs(dividend);
    	long dvs = labs(divisor);
    	auto res = 0;
    	while (dvd >= dvs) {
    		dvd -= dvs;
    		res++;
    	}
    	return sign == 1 ? res : -res;
    }
};