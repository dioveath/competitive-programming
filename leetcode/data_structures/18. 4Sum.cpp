// 18. 4Sum
// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.
// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]
 

// Constraints:

// 1 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        
        // sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            unordered_map<int, pair<int, int>> um;
            
            for(int j = i+1; j < nums.size(); j++){
                int nw_tgt = target - (nums[i] + nums[j]);
                um[nw_tgt] = {nums[i], nums[j]};
            }
            
            for(int j = i+2; j < nums.size(); j++){
                for(int k = j+1; k < nums.size(); k++){
                    if(um.find(nums[j] + nums[k]) == um.end()) continue;
                    pair<int, int> tup = um[nums[j] + nums[k]];
                    vector<int> qtup = { nums[j], nums[k], tup.first, tup.second };
                    sort(qtup.begin(), qtup.end());
                    res.insert(qtup);
                    um.erase(nums[j] + nums[k]);                    
                }
            }
        }
                
        return vector(res.begin(), res.end());
    }
};
