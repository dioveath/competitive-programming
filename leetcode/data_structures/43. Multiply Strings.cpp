// 43. Multiply Strings
// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
// Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

// Example 1:

// Input: num1 = "2", num2 = "3"
// Output: "6"
// Example 2:

// Input: num1 = "123", num2 = "456"
// Output: "56088"
 

// Constraints:

// 1 <= num1.length, num2.length <= 200
// num1 and num2 consist of digits only.
// Both num1 and num2 do not contain any leading zero, except the number 0 itself.


class Solution {
public:
    string multiply(string num1, string num2) {
        string res = "";
        for(int i = num1.length()-1; i >= 0; i--){
            int d = 0, c = 0;
            string tr = "";
            for(int j = num2.length()-1; j >= 0; j--) {
                int prod = (num1[i]-'0') * ((num2[j]-'0'));                
                prod += c;
                c = prod/10;
                d = prod%10;
                tr += '0'+d;
            }
            if(c) tr += '0'+c;            

            reverse(tr.begin(), tr.end());
            int k = (num1.length()-1)-i;
            while(k--) tr += '0';
                                    
            res = addStrings(res, tr);
        }
        
        while(res.length() > 1 && res[0] == '0') res = res.substr(1, res.length());
        return res;
    }

    string addStrings(string num1, string num2) {
        if(num1.length() < num2.length()) swap(num1, num2);
        
        string res = "";
        int c = 0;
        int i = num1.length()-1, j = num2.length()-1;
        while(i >= 0){
            int add = c; 
            add += num1[i] - '0';
            if(j >= 0) add += num2[j] - '0';
            c = add/10;
            res += add%10 + '0';
            i--; j--;
        }
        if(c) res += c + '0';
                
        reverse(res.begin(), res.end());
        return res;
    }    
    
};
