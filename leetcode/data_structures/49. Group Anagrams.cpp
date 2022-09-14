// 49. Group Anagrams
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Example 2:

// Input: strs = [""]
// Output: [[""]]
// Example 3:

// Input: strs = ["a"]
// Output: [["a"]]
 

// Constraints:

// 1 <= strs.length <= 104
// 0 <= strs[i].length <= 100
// strs[i] consists of lowercase English letters.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> um;
  
        int k = 0;
        for(int i = 0; i < strs.size(); i++){
            string tm = strs[i];
            sort(tm.begin(), tm.end());

            if(um.find(tm) != um.end()){
                res[um[tm]].push_back(strs[i]);
            } else { 
                um[tm] = k++;
                res.push_back({strs[i]});
            }
        }
        
        return res;
    }
};
