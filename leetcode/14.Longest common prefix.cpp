// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".
// Example 1:
// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:
// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
// Constraints:
// 1 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] consists of only lowercase English letters.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {        
        string result;
        for(int i = 0; i < strs[0].length(); i++){            
            char comp = strs[0][i];
            for(int j = 1; j < strs.size(); j++){
                if(strs[j][i] != comp) return result;
            }
            result += comp;
        }
        
        return result;
    }
};
