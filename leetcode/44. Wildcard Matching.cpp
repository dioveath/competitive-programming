// 44. Wildcard Matching
// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

 

// Example 1:

// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:

// Input: s = "aa", p = "*"
// Output: true
// Explanation: '*' matches any sequence.
// Example 3:

// Input: s = "cb", p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 

// Constraints:

// 0 <= s.length, p.length <= 2000
// s contains only lowercase English letters.
// p contains only lowercase English letters, '?' or '*'.


class Solution {
public:
    bool isMatch(string s, string p) {
        int plen = p.length(), slen = s.length();
        vector<vector<bool>> dp(slen+1, vector(plen+1, false));
        dp[0][0] = true;

        for(int i = 0; i < plen && p[i] == '*'; i++)
            dp[0][i+1] = true;

        for(int i = 1; i <= slen; i++){
            for(int j = 1; j <= plen; j++){
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];                   
                } else { 
                    dp[i][j] = (s[i-1] == p[j-1] || p[j-1] == '?') && dp[i-1][j-1];
                }
            }
        }

        return dp[slen][plen];
    }
};
