// 2444. Count Subarrays With Fixed Bounds
// You are given an integer array nums and two integers minK and maxK.
// A fixed-bound subarray of nums is a subarray that satisfies the following conditions:
// The minimum value in the subarray is equal to minK.
// The maximum value in the subarray is equal to maxK.
// Return the number of fixed-bound subarrays.

// A subarray is a contiguous part of an array.

// Example 1:
// Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
// Output: 2
// Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].

// Example 2:
// Input: nums = [1,1,1,1], minK = 1, maxK = 1
// Output: 10
// Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.

// Constraints:
// 2 <= nums.length <= 105
// 1 <= nums[i], minK, maxK <= 106

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minPos = -1, maxPos = -1, leftBound = -1;
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < minK || nums[i] > maxK) 
                leftBound = i;
            if(nums[i] == minK)
                minPos = i;
            if(nums[i] == maxK)
                maxPos = i;

            ans += max(0, min(minPos, maxPos) - leftBound);
        }
        return ans;
    }
};
