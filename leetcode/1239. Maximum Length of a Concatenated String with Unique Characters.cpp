// 1239. Maximum Length of a Concatenated String with Unique Characters

// You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.
// Return the maximum possible length of s.
// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

// Example 1:

// Input: arr = ["un","iq","ue"]
// Output: 4
// Explanation: All the valid concatenations are:
// - ""
// - "un"
// - "iq"
// - "ue"
// - "uniq" ("un" + "iq")
// - "ique" ("iq" + "ue")
// Maximum length is 4.
// Example 2:

// Input: arr = ["cha","r","act","ers"]
// Output: 6
// Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").
// Example 3:

// Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
// Output: 26
// Explanation: The only string in arr has all 26 characters.
 

// Constraints:

// 1 <= arr.length <= 16
// 1 <= arr[i].length <= 26
// arr[i] contains only lowercase English letters.

// NOTE:(Saroj) This solution not working. See below
// TODO:(Saroj) Fix the solution
class Solution {
public:
    int maxLength(vector<string>& arr) { 
        int mask = 0x0;
        return backtrack(arr, mask, 0);
    }
    
    int backtrack(vector<string> arr, int mask, int idx){
        if(idx == arr.size()) return 0;
        
        for(auto c : arr[idx]) {
            if(mask & (1 << (c-'a'))) return 0;            
        }        
    
        int max_len = 0;
        for(int i = idx; i < arr.size(); i++){
            for(auto c : arr[i]) mask |= (1 << (c-'a'));                
            int len = 0, tmp_mask = mask;
            while(tmp_mask){
                len++;
                tmp_mask &= (tmp_mask-1);
            }
    
            max_len = max(len, backtrack(arr, mask, i+1));
        }
        
        return max_len;
    }
    
    void print_binary(int a){
        int n = 32;
        while(n--){
            int bit = a & 1;
            cout << bit;
            a >>= 1;
        }
        cout << endl;
    }
};


class Solution {
public:
    int maxLength(vector<string>& arr, string s="", int idx=0) { 
        unordered_set<char> us(s.begin(), s.end());
        if(us.size() != s.length()) return 0;
        
        int len = s.length();
        for(int i = idx; i < arr.size(); i++)
            len = max(len, maxLength(arr, s+arr[i], i+1));
        return len;
    }
        
};
