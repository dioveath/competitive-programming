// 139. Word Break
// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
// Note that the same word in the dictionary may be reused multiple times in the segmentation.

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:

// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false
 

// Constraints:

// 1 <= s.length <= 300
// 1 <= wordDict.length <= 1000
// 1 <= wordDict[i].length <= 20
// s and wordDict[i] consist of only lowercase English letters.
// All the strings of wordDict are unique.



class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> word_set;
        vector<int> dp(s.length(), -1);
        for(auto s : wordDict) word_set.insert(s);
        return wordBreakHelper(s, 0, word_set, dp);
    }

    bool wordBreakHelper(string& s, int i, set<string>& word_set, vector<int>& dp){
        int slen = s.length();
        if(i == slen) return true;
        if(dp[i] != -1) return dp[i];
        for(int j = i; j < slen; j++){
            if(word_set.find(s.substr(i, j-i+1)) == word_set.end()) continue;
            if(wordBreakHelper(s, j+1, word_set, dp)) return dp[i] = true;
        }
        return dp[i] = false;
    }
};
