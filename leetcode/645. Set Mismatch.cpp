// 645. Set Mismatch
// You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
// You are given an integer array nums representing the data status of this set after the error.
// Find the number that occurs twice and the number that is missing and return them in the form of an array.
// Example 1:

// Input: nums = [1,2,2,4]
// Output: [2,3]
// Example 2:

// Input: nums = [1,1]
// Output: [1,2]

// Constraints:

// 2 <= nums.length <= 104
// 1 <= nums[i] <= 104

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans(2, 0);
        int prev = 0;
        for(int i = 0; i < nums.size(); i++) {
            if((nums[i] - prev) == 2) ans[1] = nums[i]-1;
            if((nums[i] - prev) == 0) ans[0] = nums[i];
            prev = nums[i];
        }
        if(!ans[1]) ans[1] = nums[nums.size()-1]+1;
        return ans;
    }
};
