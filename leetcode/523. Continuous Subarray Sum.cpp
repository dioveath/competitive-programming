// 523. Continuous Subarray Sum
// Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.
// An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
// Example 1:

// Input: nums = [23,2,4,6,7], k = 6
// Output: true
// Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
// Example 2:

// Input: nums = [23,2,6,4,7], k = 6
// Output: true
// Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
// 42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
// Example 3:

// Input: nums = [23,2,6,4,7], k = 13
// Output: false

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 109
// 0 <= sum(nums[i]) <= 231 - 1
// 1 <= k <= 231 - 1


// NOTE:(Not solution, see below)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // for(int i = 0; i < nums.size(); i++){
        //     int sum = nums[i];
        //     for(int j = i+1; j < nums.size(); j++){
        //         sum += nums[j];
        //         if(sum % k == 0) return true;
        //     }
        // }
        // return false;
        
        // 2nd Solution: two-pointer approach
        // [1, 2, 3, 4]. k = 5
        // 1. 1+2+3+4 = 10 
        // 2. 2+3 = 9
        
//         multiple of k:
//         1. sum%k == 0;
        
//         [1, 2, 3, 6] k = 5
//         1+2+3+6 = 12
            
//         [2, 3, 6] k = 5
//         2+3+6 = 12
            
        for(int i = 1; i < nums.size(); i++){
            nums[i] = nums[i-1] + nums[i];
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % k == 0) return true;
        }

    }
};




// NOTE:(This is solution)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap({{0, -1}});
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(k != 0) sum %= k;
            if(umap.find(sum) != umap.end()) { 
                if(i-umap[sum] >= 2) return true;
            } else { 
                umap[sum] = i;
            }
        }
        return false;
    }
};
