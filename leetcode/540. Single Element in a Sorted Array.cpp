// 540. Single Element in a Sorted Array
// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
// Return the single element that appears only once.
// Your solution must run in O(log n) time and O(1) space.

// Example 1:
// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2

// Example 2:
// Input: nums = [3,3,7,7,10,11,11]
// Output: 10

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 105

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int m = 0;
        while(l < r){
            m = (l+r)/2;
            if(m % 2 == 1) m--;
            if(nums[m] == nums[m+1]) l = m+2;
            else r = m;
        }
        
        return nums[l];
    }
};