// 784. Letter Case Permutation
// Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.
// Return a list of all possible strings we could create. Return the output in any order.

// Example 1:

// Input: s = "a1b2"
// Output: ["a1b2","a1B2","A1b2","A1B2"]
// Example 2:

// Input: s = "3z4"
// Output: ["3z4","3Z4"]

// Constraints:

// 1 <= s.length <= 12
// s consists of lowercase English letters, uppercase English letters, and digits.

class Solution {
public:
    vector<string> res;
    vector<string> letterCasePermutation(string s) {
        backtrack(s, 0);
        return res;
    }
    
    void backtrack(string s, int idx){
        if(idx >= s.length()) { res.push_back(s); return; }
        
        if(s[idx] >= '0' && s[idx] <= '9') { backtrack(s, idx+1); return; }
        
        backtrack(s, idx+1);        
        
        if(s[idx] >= 'a' && s[idx] <= 'z') {
            s[idx] = 'Z' - ('z' - s[idx]);    
        } else if(s[idx] >= 'A' && s[idx] <= 'Z') { 
            s[idx] = 'z' - ('Z' - s[idx]);
        } 
        
        backtrack(s, idx+1);
            
    }

};
