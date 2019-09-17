/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 */
class Solution {
public:
    string digits[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    string helper(int n) {
        if (n >= 1000000000) {
            return helper(n / 1000000000) + " " + "Billion" + helper(n % 1000000000);
        } else if (n >= 1000000) {
            return helper(n / 1000000) + " " + "Million" + helper(n % 1000000);
        }  else if (n >= 1000) {
            return helper(n / 1000) + " " + "Thousand" + helper(n % 1000);
        } else if (n >= 100) {
            return helper(n / 100) + " " + "Hundred" + helper(n % 100);
        } else if (n >= 20) {
            return " " + tens[n / 10] + helper(n % 10);
        } else if (n >= 1) {
            return " " + digits[n];
        } else {
            return "";
        }
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";
        return helper(num).substr(1);
    }
};

