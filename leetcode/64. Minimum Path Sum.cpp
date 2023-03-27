// 64. Minimum Path Sum
// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

 

// Example 1:


// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
// Example 2:

// Input: grid = [[1,2,3],[4,5,6]]
// Output: 12
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 200
// 0 <= grid[i][j] <= 100

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {  
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(grid, dp, 0, 0);
    } 

    int dfs(vector<vector<int>>& grid, vector<vector<int>>& dp, int y, int x){
        int m = grid.size(), n = grid[0].size();
        if(y == m-1 && x == n-1) { return grid[y][x]; }
        if(x >= n || y >= m) return INT_MAX;

        if(dp[y][x] != -1) return dp[y][x];
        int down  = dfs(grid, dp, y+1, x);
        int right = dfs(grid, dp, y, x+1);

        return dp[y][x] = grid[y][x] + min(down, right);
    }
};
