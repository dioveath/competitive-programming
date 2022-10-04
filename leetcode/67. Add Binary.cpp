// 67. Add Binary
// Given two binary strings a and b, return their sum as a binary string.

// Example 1:

// Input: a = "11", b = "1"
// Output: "100"
// Example 2:

// Input: a = "1010", b = "1011"
// Output: "10101"
 

// Constraints:

// 1 <= a.length, b.length <= 104
// a and b consist only of '0' or '1' characters.
// Each string does not contain leading zeros except for the zero itself.

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() < b.length()) swap(a, b);
        string res = ""; int c = 0;
        int i = a.length()-1, j = b.length()-1; 
        while(i >= 0){
            int sum = (a[i]-'0') + (j >= 0 ? b[j]-'0' : 0) + c;
            if(sum > 1) c = 1;
            else c = 0;         
            if(sum == 2 || sum == 0) res += '0';
            else res += '1';
            i--; j--;
        }
        if(c) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};
