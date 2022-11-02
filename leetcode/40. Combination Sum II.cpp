// 40. Combination Sum II
// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

// Example 1:
// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]
// Constraints:

// 1 <= candidates.length <= 100
// 1 <= candidates[i] <= 50
// 1 <= target <= 30


class Solution {
public:
    set<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> check; 
        recurse(candidates, target, 0, {}, check);
        return vector(res.begin(), res.end());
    }
    
    void recurse(vector<int>& cans, int target, int curr, int idx, vector<int>& vect) {        
        for(int i = idx; i < cans.size(); i++){
            if(i > idx && cans[i] == cans[i-1]) continue;
            int csum = curr + cans[i];
            
            vect.push_back(cans[i]);
            if(csum == target) { res.insert(vect); }
            if(csum < target) { 
                recurse(cans, target, csum, i+1, vect);
            }
            vect.pop_back();
        }
    }
};
