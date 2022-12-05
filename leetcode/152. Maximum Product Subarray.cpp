// 152. Maximum Product Subarray
// Given an integer array nums, find a 
// subarray
//  that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.
// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

// Constraints:

// 1 <= nums.length <= 2 * 104
// -10 <= nums[i] <= 10
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n,1), pos(n,1);
        int ans = -INT_MAX;

        pre[0] = nums[0];
        ans = max(ans, pre[0]);
        for(int i = 1; i < n; i++) {
            if(nums[i-1] == 0) pre[i] = nums[i];
	    else pre[i] = pre[i-1] * nums[i];

            ans = max(ans, pre[i]);
        }

        pos[n-1] = nums[n-1];
        ans = max(ans, pos[n-1]);
        for(int i = n-2; i >= 0; i--) {
            if(nums[i+1] == 0) pos[i] = nums[i];
	    else pos[i] = pos[i+1] * nums[i];

            ans = max(ans, pos[i]);
        }

        return ans;
    }
};
