class Solution {
public:
    int climbStairs(int n) {
    	if (n == 0) {
    		return 0;
    	}
    	if (n == 1) {
    		return 1;
    	}
    	if (n == 2) {
    		return 2;
    	}
    	int destination = 0;
    	int one_step_away = 2;
    	int two_step_away = 1;
    	for (auto i = 2; i < n; ++i) {
    		destination = one_step_away + two_step_away;
    		two_step_away = one_step_away;
        	one_step_away = destination;
    	}
    	return destination;
    }
};