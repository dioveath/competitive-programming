// 22. Generate Parenthesis
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]
 

// Constraints:

// 1 <= n <= 8


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(res, n, n, "");
        return res;
    }
    
    void generate(vector<string>& res, int open, int close, string temp){
        if(open == 0 && close == 0) {
            res.push_back(temp);
            return;
        }
        
        if(open > 0) generate(res, open - 1, close, temp + "(");
        if(close > open) generate(res, open, close - 1, temp + ")");
    }
};
