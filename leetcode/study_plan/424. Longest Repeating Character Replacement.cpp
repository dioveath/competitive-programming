// 424. Longest Repeating Character Replacement
// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

// Example 1:

// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.
// Example 2:

// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
 

// Constraints:

// 1 <= s.length <= 105
// s consists of only uppercase English letters.
// 0 <= k <= s.length


class Solution {
public:
    int characterReplacement(string s, int k) {
        int max = 1;
        int i = 0, j = 1;
        int freq[26] = {0};
        freq['Z'-s[0]]++;
        char max_char = s[0];
        int op = 0;
        while(j < s.length()){
            freq['Z'-s[j]]++;
            if(freq['Z'-s[j]] > freq['Z'-max_char]) max_char = s[j];
            if(s[j] != max_char) op++;
            
            if(op > k) { 
                for(int i = 0; i < 26; i++) freq[i] = 0;
                op = 0;
                i++;
                j = i+1;
                max_char = s[i];
                freq['Z'-s[i]]++;
                continue;
            }
            
            if((j-i)+1 > max) max = j-i+1;
            j++;
        }
        
        return max;
    }
};
