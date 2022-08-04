//567. Permutation in String
// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
// In other words, return true if one of s1's permutations is the substring of s2.

// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false
 

// Constraints:

// 1 <= s1.length, s2.length <= 104
// s1 and s2 consist of lowercase English letters.

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int fr[26] = {0};
        for(char ch : s1) fr[ch - 'a']++;
        
        int cfr[26] = {0};
        int start = 0, end = 0;
        while(end < s2.length()){
            cfr[s2[end] - 'a']++;
            if((end - start) + 1 == s1.length() || cfr[s2[end] - 'a'] > fr[s2[end] - 'a']){
                if(checkFreq(fr, cfr)) return true;             
                cfr[s2[start] - 'a']--;
                start++;
            }
            end++;
        }
        
        return false;
    }
    
    bool checkFreq(int* fr, int* cfr) {
        for(int i = 0; i < 26; i++)
            if(fr[i] != cfr[i]) return false;
        return true;
    }
};
