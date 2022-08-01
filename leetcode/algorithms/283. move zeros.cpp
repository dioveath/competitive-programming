// 283. Move Zero
// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

 

// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Example 2:

// Input: nums = [0]
// Output: [0]
 

// Constraints:

// 1 <= nums.length <= 104
// -231 <= nums[i] <= 231 - 1
 

// Follow up: Could you minimize the total number of operations done?


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp = nums;
        for(int i = 0, j = 0; i < nums.size(); i++){
            if(temp[i] == 0) { 
                nums[nums.size() - j - 1] = 0;
                j++;
            } else {
                nums[i-j] = temp[i];
            }
        }
    }

};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i = 0, j = 0; i < nums.size(); i++){
	  if(nums[i] != 0) {
	    nums[j] = nums[i];
	    if(i > j) nums[i] = 0;
	    j++;
	  }
        }
    }

};


