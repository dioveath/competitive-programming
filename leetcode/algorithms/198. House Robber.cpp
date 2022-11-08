// 198. House Robber
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 2:

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 400

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        vector<int> dp(n, 0);
        dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++)
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);

        return dp[n-1];
    }
};


class Solution {
public:
    int dp[100];
    int rob(vector<int>& nums) {
        for(int i = 0; i < 100; i++) dp[i] = -1;
        return rob_max(nums, 0);
    }
    
    int rob_max(vector<int> nums, int idx){
        if(idx >= nums.size()) return 0;
        if(idx == nums.size()-1) return nums[idx];
        if(idx == nums.size()-2) return nums[idx] > nums[idx+1] ? nums[idx] : nums[idx+1];        
        
        if(dp[idx] != -1) return dp[idx];
        
        int rob1 = nums[idx] + rob_max(nums, idx+2);
        int rob2 = nums[idx+1] + rob_max(nums, idx+3);
        
        int res =  rob1 > rob2 ? rob1 : rob2;
        dp[idx] = res;
        return res;
    }
    

};


