class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> res;
        generateParenthesisDFS(res, "", n, n);
        return res;
    }

    void generateParenthesisDFS(vector<string> & res, string out, int left, int right){
        if (left > right) {
            return;
        }
        if(left == 0 && right == 0){
            res.push_back(out);
            return;
        }
        if(left > 0) generateParenthesisDFS(res, out + "(", left - 1, right);
        if(right > 0) generateParenthesisDFS(res, out + ")", left, right - 1);
    }
};