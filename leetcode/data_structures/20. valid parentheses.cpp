// 20. Valid Parentheses
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Example 1:
// Input: s = "()"
// Output: true
// Example 2:
// Input: s = "()[]{}"
// Output: true
// Example 3:
// Input: s = "(]"
// Output: false
// Constraints:
// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.

class Solution {
public:
    bool isValid(string s) {
        if(s.length() % 2 == 1) return false;
        stack<char> st;
        unordered_map<char, char> map;
        map.insert({'(', ')'});
        map.insert({'{', '}'});
        map.insert({'[', ']'});
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if(st.empty() || map[st.top()] != s[i]) return false;
                st.pop();
            } else { 
                st.push(s[i]);
            }
        }

        return st.size() == 0;
    }
};
