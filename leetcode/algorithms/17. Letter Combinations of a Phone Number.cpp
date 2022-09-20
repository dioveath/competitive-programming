// 17. Letter Combinations of a Phone Number

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]
 

// Constraints:

// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].


class Solution {
public:
    vector<string> res;
    vector<vector<char>> pad = {{},{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'},
                                {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'},
                                {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
    
    vector<string> letterCombinations(string digits) {
        if(!digits.length()) return {};
        recurse(0, digits, "");
        return res;
    }
    
    void recurse(int idx, string digits, string s){
        for(int j = 0; j < pad[digits[idx]-'0'-1].size(); j++){
            string tmp = s;                
            tmp += pad[digits[idx]-'0'-1][j];
            if(tmp.length() == digits.length()) res.push_back(tmp);
            else recurse(idx+1, digits, tmp);
        }
    }
};
