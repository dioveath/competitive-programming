// 844. Backspace string compare
// Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
// Note that after backspacing an empty text, the text will continue empty.

// Example 1:

// Input: s = "ab#c", t = "ad#c"
// Output: true
// Explanation: Both s and t become "ac".
// Example 2:

// Input: s = "ab##", t = "c#d#"
// Output: true
// Explanation: Both s and t become "".
// Example 3:

// Input: s = "a#c", t = "b"
// Output: false
// Explanation: s becomes "c" while t becomes "b".
 

// Constraints:

// 1 <= s.length, t.length <= 200
// s and t only contain lowercase letters and '#' characters.

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int unmatch = 0;
        stack<char> st1, st2;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '#' && !st1.empty()) st1.pop();
            else if(s[i] != '#') st1.push(s[i]);    
        }
        
        for(int j = 0;j < t.length(); j++){
            if(t[j] == '#' && !st2.empty()) st2.pop();
            else if(t[j] != '#')st2.push(t[j]);            
        }

        if(st1.size() != st2.size()) return false;
        
        while(!st1.empty()){
            if(st1.top() != st2.top()) return false;
            st1.pop(); st2.pop();
        }
        
        return true;
    }
};
