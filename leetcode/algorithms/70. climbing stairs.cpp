// 70. Climbing Stairs
// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
// Example 1:
// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step
// Constraints:

// 1 <= n <= 45

class Solution {
public:
    int dp[45] = {0};
    int climbStairs(int n) {      
        if(n == 1) return 1; 
        if(n == 2) return 2;
        if(dp[n-1] == 0) dp[n-1] = climbStairs(n-1) + climbStairs(n-2);
        return dp[n-1];
    }
};

class Solution {
public:
    int climbStairs(int n) {      
        if(n <= 2) return n;
        int a = 1, b = 1;
        while(--n >= 1){ 
            int t = b;
            b += a;
            a = t;
        }
        return b;
    }
};
