// 16. 3Sum Closest
// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
// Return the sum of the three integers.
// You may assume that each input would have exactly one solution.

// Example 1:
// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
// Example 2:

// Input: nums = [0,0,0], target = 1
// Output: 0
// Constraints:

// 3 <= nums.length <= 1000
// -1000 <= nums[i] <= 1000
// -104 <= target <= 104


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        long closest = INT_MAX;
        int j = 0, k = 0;
        for(int i = 0; i+2 < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            j = i+1;
            k = nums.size() - 1;
            
            while(j < k){
                long sum = nums[i] + nums[j] + nums[k];
                if(sum == target) return sum;
                if(abs(target - sum) < abs(target - closest)) closest = sum;
                
                if(sum > target) {
                    k--;
                    while(j < k && nums[k] == nums[k+1]) k--;
                } else j++;
            }
        }
        
        return closest;
    }
};
