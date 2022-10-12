// 976. Largest Perimeter Triangle
// Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.

// Example 1:

// Input: nums = [2,1,2]
// Output: 5
// Example 2:

// Input: nums = [1,2,1]
// Output: 0
 

// Constraints:

// 3 <= nums.length <= 104
// 1 <= nums[i] <= 106

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        while(n > 2 && nums[n-2]+nums[n-3] <= nums[n-1]) n--;
        if(n <= 2) return 0;
        return nums[n-1] + nums[n-2] + nums[n-3];
    }
};
