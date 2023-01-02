// 520. Detect Capital
// We define the usage of capitals in a word to be right when one of the following cases holds:

// All letters in this word are capitals, like "USA".
// All letters in this word are not capitals, like "leetcode".
// Only the first letter in this word is capital, like "Google".
// Given a string word, return true if the usage of capitals in it is right.

// Example 1:
// Input: word = "USA"
// Output: true

// Example 2:
// Input: word = "FlaG"
// Output: false
 
// Constraints:
// 1 <= word.length <= 100
// word consists of lowercase and uppercase English letters.

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() == 1) return true;
        if(!isupper(word[0]) && isupper(word[1])) return false;
        bool all_capital = isupper(word[1]);
        for(int i = 1; i < word.length(); i++)
            if(all_capital && !isupper(word[i])) return false;
            else if(!all_capital && isupper(word[i])) return false;
        return true;
    }
};
