class Solution {
public:
    string addBinary(string a, string b) {
        auto len_a = a.length();
        auto len_b = b.length();
        auto int_a = 0;
        auto int_b = 0;
        for (auto i = 0; i < len_a; ++i) {
        	if (a[i] == '1') {
        		int_a += pow(2, len_a - i - 1);
        	}
        }
        for (auto i = 0; i < len_b; ++i) {
        	if (b[i] == '1') {
        		int_b += pow(2, len_b - i - 1);
        	}
        }
        auto int_c = int_a + int_b;
        auto index = 0;
        string reverse_str;
        char *p = new char[50];
        while (int_c >= 1) {
        	auto divider = int_c / 2;
        	auto residual = int_c - divider * 2;
        	*(p + index) = residual + '0';
        	index++;
        	int_c /= 2;
        }
        reverse_str = p;
        delete []p;
        reverse(reverse_str.begin(), reverse_str.end());
        if (reverse_str.empty()) {
            string str = "0";
            return str;
        }
        return reverse_str;
    }
};