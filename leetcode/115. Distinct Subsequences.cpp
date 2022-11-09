// 115. Distinct Subsequences
// Given two strings s and t, return the number of distinct 
// subsequences
//  of s which equals t.

// The test cases are generated so that the answer fits on a 32-bit signed integer.

 

// Example 1:

// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from s.
// rabbbit
// rabbbit
// rabbbit
// Example 2:

// Input: s = "babgbag", t = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from s.
// babgbag
// babgbag
// babgbag
// babgbag
// babgbag
 

// Constraints:

// 1 <= s.length, t.length <= 1000
// s and t consist of English letters.


class Solution {
public:
    int numDistinct(string s, string t) {
        int slen = s.length(), tlen = t.length();

        unsigned long long dp[1001][1001];
        memset(dp, 0, sizeof dp);

        for(int j = 0; j <= slen; j++) 
            dp[0][j] = 1;

        for(int i = 1; i <= tlen; i++){
            for(int j = 1; j <= slen; j++){
                if(t[i-1] == s[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }

        return dp[tlen][slen];
    }

};
