// 76. Minimum Window Substring
// Given two strings s and t of lengths m and n respectively, return the minimum window 
// substring
//  of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.
 

// Constraints:

// m == s.length
// n == t.length
// 1 <= m, n <= 105
// s and t consist of uppercase and lowercase English letters.
 

// Follow up: Could you find an algorithm that runs in O(m + n) time?


class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tmp;
        for(auto ch : t) tmp[ch]++;
        unordered_map<char, int> check;

        int ansL = -1, ansR = -1;

        int left = 0, right = 0;
        int formed = 0, required = tmp.size();
        while(right < s.length()){
            if(!tmp[s[right]]) { right++; continue; }
            
            check[s[right]]++;
            if(check[s[right]] == tmp[s[right]]) formed++;

            while(left <= right && formed == required) {
                if(!tmp[s[left]]) { left++; continue; }

                if(ansR == -1 || (right-left+1) < (ansR-ansL+1)) {
                    ansL = left;
                    ansR = right;
                }

                check[s[left]]--;
                if(check[s[left]] < tmp[s[left]]) { 
                    formed--;
                }
                left++;
            }
            right++;
        }

        if(ansL == -1) return "";
        return s.substr(ansL, ansR-ansL+1);
    }
};  
