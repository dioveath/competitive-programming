// 65. Valid Number
// A valid number can be split up into these components (in order):

// A decimal number or an integer.
// (Optional) An 'e' or 'E', followed by an integer.
// A decimal number can be split up into these components (in order):

// (Optional) A sign character (either '+' or '-').
// One of the following formats:
// One or more digits, followed by a dot '.'.
// One or more digits, followed by a dot '.', followed by one or more digits.
// A dot '.', followed by one or more digits.
// An integer can be split up into these components (in order):

// (Optional) A sign character (either '+' or '-').
// One or more digits.
// For example, all the following are valid numbers: ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].

// Given a string s, return true if s is a valid number.

 

// Example 1:

// Input: s = "0"
// Output: true
// Example 2:

// Input: s = "e"
// Output: false
// Example 3:

// Input: s = "."
// Output: false
 

// Constraints:

// 1 <= s.length <= 20
// s consists of only English letters (both uppercase and lowercase), digits (0-9), plus '+', minus '-', or dot '.'.

class Solution {
public:
    bool isNumber(string s) {
        int j = 0;
        while(j < s.length() && !(s[j] == 'e' || s[j] == 'E')) j++;

        string decimal = s.substr(0, j+1);
        if(decimal == "") return false;

        if(j == s.length()) return isSignDecimal(s, 0, j-1);
        return isSignDecimal(s, 0, j-1) && isInteger(s, j+1, s.length()-1);
    }

    bool isSignDecimal(string s, int i, int end){
        if(s == "" || i > end) return false;
        if(s[i] == '+' || s[i] == '-') {
            if(i+1 > end) return false;
            return isDecimal(s, i+1, end);
        }
        return isDecimal(s, i, end);
    }

    bool isDecimal(string s, int i, int end) {
        if(s == "" || i > end) return true;
        if(s[i] == '.') return isDigit(s, i+1, end);
        int j = i;
        while(j <= end && s[j] != '.') j++;
        if(j == end+1) return isDigit(s, i, end);
        return isDigit(s, i, j-1) && (j == end || isDigit(s, j+1, end));
    }
    
    bool isInteger(string s, int i, int end) {
        if(s == "" || i > end) return false;
        if(s[i] == '+' | s[i] == '-') return isDigit(s, i+1, end);
        return isDigit(s, i, end);
    }

    bool isDigit(string s, int i, int end){
        if(s == "" || i > end) return false;
        while(i <= end && s[i] >= '0' && s[i] <= '9') i++;
        return i-1 == end;
    }

};