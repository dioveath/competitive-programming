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
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        int n = nums.size();
        for(int i = 0; i < n-3; i++){
            for(int j = i+1; j < n-2; j++){
                long long toFind = (long long) target - (long long)(nums[i] + nums[j]);
                int low = j+1, high = n-1;
                while(low < high){
                    long long found = nums[low] + nums[high];
                    if(found == toFind){
                        ans.insert({ nums[i], nums[j], nums[low], nums[high]});
                        low++; high--;
                    } else if(found < toFind) low++;
                    else high--;
                }
            }
        }
        return vector(ans.begin(), ans.end());
    }
};

