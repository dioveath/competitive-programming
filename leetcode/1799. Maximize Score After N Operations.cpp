// 1799. Maximize Score After N Operations
// You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.

// In the ith operation (1-indexed), you will:

// Choose two elements, x and y.
// Receive a score of i * gcd(x, y).
// Remove x and y from nums.
// Return the maximum score you can receive after performing n operations.

// The function gcd(x, y) is the greatest common divisor of x and y.

 

// Example 1:

// Input: nums = [1,2]
// Output: 1
// Explanation: The optimal choice of operations is:
// (1 * gcd(1, 2)) = 1
// Example 2:

// Input: nums = [3,4,6,8]
// Output: 11
// Explanation: The optimal choice of operations is:
// (1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
// Example 3:

// Input: nums = [1,2,3,4,5,6]
// Output: 14
// Explanation: The optimal choice of operations is:
// (1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
 

// Constraints:

// 1 <= n <= 7
// nums.length == 2 * n
// 1 <= nums[i] <= 106


class Solution {
public:
    int maxScore(vector<int>& nums) {
        int memoSize = 1 << nums.size();
        vector<int> memo(memoSize, -1);
        return backtrack(nums, 0, 0, memo);
    }

    int backtrack(vector<int>& nums, int mask, int pairsPicked, vector<int>& memo) {
        if(2 * pairsPicked == nums.size()) return 0;
        if(memo[mask] != -1) return memo[mask];

        int maxScore = 0;

        for(int firstIndex = 0; firstIndex < nums.size(); firstIndex++){
            for(int secondIndex = firstIndex + 1; secondIndex < nums.size(); secondIndex++){
                if(((mask >> firstIndex) & 1) == 1 || ((mask >> secondIndex) & 1) == 1) 
                    continue;
                int newMask = mask | (1 << firstIndex) | ((1 << secondIndex));
                int currScore = (pairsPicked+1) * __gcd(nums[firstIndex], nums[secondIndex]);
                int remainingScore = backtrack(nums, newMask, pairsPicked+1, memo);
                maxScore = max(maxScore, currScore + remainingScore);
            }
        }

        memo[mask] = maxScore;
        return maxScore;
    }


};
