// 200. Number of islands
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int dir_x[4] = { 1, -1,  0,  0};
        int dir_y[4] = { 0,  0,  1, -1};
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '0') continue;

                count++;
                
                queue<pair<int, int>> q({{i, j}});                
                while(!q.empty()){
                    pair<int, int> pos = q.front();
                    q.pop();
                    
                    for(int k = 0; k < 4; k++){
                        int dx = pos.second + dir_x[k];
                        int dy = pos.first  + dir_y[k];
                        if(dx < 0 || dx >= grid[i].size() || dy < 0 || dy >= grid.size()) continue;
                        if(grid[dy][dx] == '0') continue;
                        q.push({dy, dx});
                        grid[dy][dx] = '0';
                    }
                }
            }            
        }
        return count;
    }
};
