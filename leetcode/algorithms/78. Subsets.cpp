// 78. Subsets
// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.
// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.


class Solution {
public:
    unordered_set<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.insert({});
        backtrack(nums, 0, {});
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
    
    void backtrack(vector<int> nums, int i, vector<int> curr){
        if(i >= nums.size()) return;
        while(i < nums.size()){
            vector<int> temp = curr;
            temp.push_back(nums[i]);
            res.insert(temp);
            backtrack(nums, i+1, temp);
            i++;
        }
    }
};
