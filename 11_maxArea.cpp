// Time limit exceeded
class Solution {
public:
    int maxArea(vector<int>& height) {
    	vector<pair<int, int>> point;
    	point.clear();
    	auto len = height.size();
    	for (auto i = 0; i < len; ++i) {
    		point.push_back(make_pair(height[i], i + 1));
    	}
    	optimize(point);
        vector<int> result;
        result.clear();
        for (auto i = 0; i < len - 1; ++i) {
        	for (auto j = i + 1; j < len; ++j) {
        		result.push_back(calculateArea(point[i], point[j]));
        	}
        }
        std::sort(result.begin(), result.end());
        auto len_result = result.size();
        return result[len_result - 1];
    }

    void optimize(vector<pair<int, int>>& point) {
    	auto len = point.size();
    	for (auto i = 1; i < len - 1; ++i) {
    		if (point[i - 1].first >= point[i].first && point[i + 1].first >= point[i].first) {
    			point[i].first = -1;
    		}
    	}
    	for (auto iter = point.begin(); iter != point.end();) {
    		if (iter->first < 0) {
    			point.erase(iter);
    		} else {
    			iter++;
    		}
    	}
    }

    int calculateArea(pair<int, int> point1, pair<int, int> point2) {
    	auto height = (point1.first < point2.first) ? point1.first : point2.first;
    	return height * std::abs(point1.second - point2.second);
    }
};