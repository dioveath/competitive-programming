// 1312. Minimum Insertion Steps to Make a String Palindrome
// Given a string s. In one step you can insert any character at any index of the string.

// Return the minimum number of steps to make s palindrome.

// A Palindrome String is one that reads the same backward as well as forward.

 

// Example 1:

// Input: s = "zzazz"
// Output: 0
// Explanation: The string "zzazz" is already palindrome we do not need any insertions.
// Example 2:

// Input: s = "mbadm"
// Output: 2
// Explanation: String can be "mbdadbm" or "mdbabdm".
// Example 3:

// Input: s = "leetcode"
// Output: 5
// Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 

// Constraints:

// 1 <= s.length <= 500
// s consists of lowercase English letters.

class Solution {
public:
    int dp[501][501];
    int minInsertions(string s) {
        int n = s.length();
        string srev = s;
        reverse(srev.begin(), srev.end());
        return n - helper(s, srev, n, n);
    }


    int helper(string s, string srev, int m, int n){
        memset(dp, -1, sizeof(dp));

        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(s[i-1] == srev[j-1]) 
                    dp[i][j] = 1 + dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[m][n];
    }
};
