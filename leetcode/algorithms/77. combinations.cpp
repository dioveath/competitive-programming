// 77. Combinations 
// Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].
// You may return the answer in any order.
// Example 1:

// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
// Example 2:

// Input: n = 1, k = 1
// Output: [[1]]
// Constraints:

// 1 <= n <= 20
// 1 <= k <= n

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        backtrack(n, k, 1, v);
        return res;
    }
    
    void backtrack(int n, int k, int idx, vector<int>& v){
        if(k == 0) { res.push_back(v); return; }
        
        for(int i = idx; i <= n+1-k; i++){
            v.push_back(i);
            backtrack(n, k-1, i+1, v);
            v.pop_back();
        }
    }
    
    
};
