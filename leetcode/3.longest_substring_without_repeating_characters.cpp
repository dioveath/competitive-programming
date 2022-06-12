// 3. Longest Substring Without Repeating Characters
// Given a string s, find the length of the longest substring without repeating characters.
// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
// Constraints:
// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> longest_substring;
        vector<char> prev;
        int current_substring_start_index = 0;
        for(int i = 0; i < s.length(); i++){
            if(find(prev.begin(), prev.end(), s[i]) != prev.end()) { 
                prev.clear();
                i = current_substring_start_index;
            } else { 
                prev.push_back(s[i]);
                current_substring_start_index = i - (prev.size() - 1);
            }
            if(longest_substring.size() < prev.size()) {
                longest_substring = prev;
            }
        }
        return longest_substring.size();
    }
};
