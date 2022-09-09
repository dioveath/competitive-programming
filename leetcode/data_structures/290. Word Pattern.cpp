// 290. Word Pattern
// Given a pattern and a string s, find if s follows the same pattern.
// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.
// Example 1:

// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true
// Example 2:

// Input: pattern = "abba", s = "dog cat cat fish"
// Output: false
// Example 3:

// Input: pattern = "aaaa", s = "dog cat cat dog"
// Output: false
 

// Constraints:

// 1 <= pattern.length <= 300
// pattern contains only lower-case English letters.
// 1 <= s.length <= 3000
// s contains only lowercase English letters and spaces ' '.
// s does not contain any leading or trailing spaces.
// All the words in s are separated by a single space.


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> um;
        unordered_map<string, char> um2;
        int j = 0;
        for(int i = 0; i < pattern.length(); i++){
            string word = "";
            while(j < s.length() && s[j] != ' ') word += s[j++];
            if(um.find(pattern[i]) == um.end() && um2.find(word) == um2.end()){
                um2[word] = pattern[i];
                um[pattern[i]] = word;
            } else if (um[pattern[i]] != word || um2[word] != pattern[i]) return false;
            j++;
        }
        
        // cout << j << s.length() << endl;
        if(j != s.length()+1) return false;
        return true;
    }
};
