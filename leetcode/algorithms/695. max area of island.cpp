// 695. Max Area of Island
// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
// The area of an island is the number of cells with a value 1 in the island.
// Return the maximum area of an island in grid. If there is no island, return 0.
// Example 1:

// Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Output: 6
// Explanation: The answer is not 11, because the island must be connected 4-directionally.
// Example 2:

// Input: grid = [[0,0,0,0,0,0,0,0]]
// Output: 0
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 50
// grid[i][j] is either 0 or 1.


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int island_idx = 2;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] != 1) continue;
                int area = count_grid(grid, j, i, 0, island_idx++);
                if(area > maxArea) maxArea = area;
            }
        }
        return maxArea;
    }
    
    int count_grid(vector<vector<int>>& grid, int x, int y, int count, int idx){
        if(x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size()) return count;
        if(grid[y][x] != 1) return count;
        grid[y][x] = idx;
        return count_grid(grid, x+1,   y, count, idx) 
             + count_grid(grid, x-1,   y, count, idx)
             + count_grid(grid,   x, y+1, count, idx)
             + count_grid(grid,   x, y-1, count, idx) + 1;
    }
};
