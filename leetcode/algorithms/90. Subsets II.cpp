// 90. Subsets II
// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.
// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<string> dup;
        vector<vector<int>> res;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());  // sort to avoid adding permutation of the substring
        
        for(int i = 0; i < (1 << n); i++){
            vector<int> temp;
            string temp_str;
            for(int j = 0; j < n; j++){
                if(i & (1 << j)) {
                    temp.push_back(nums[j]);
                    temp_str += to_string(nums[j])+"$";
                }
            }
            if(find(dup.begin(), dup.end(), temp_str) == dup.end()) {
                res.push_back(temp);
                dup.push_back(temp_str);
            }
        }
        return res;
    }
};
