// 1020. Number of Enclaves
// You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
// Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

// Example 1:


// Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
// Output: 3
// Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
// Example 2:


// Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
// Output: 0
// Explanation: All 1s are either on the boundary or can reach the boundary.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 500
// grid[i][j] is either 0 or 1.

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int dir_x[4] = {1, -1, 0, 0};
        int dir_y[4] = {0, 0, 1, -1};

        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0 || vis[i][j]) continue;

                int cells = 0;    
                bool enclosed = true;            
                queue<pair<int, int>> q({{i, j}});
                vis[i][j] = true;
                while(!q.empty()){
                    auto front = q.front();
                    q.pop();
                    cells++;
                    for(int k = 0; k < 4; k++){
                        int dy = front.first + dir_y[k];
                        int dx = front.second + dir_x[k];
                        if(dx < 0 || dx >= n || dy < 0 || dy >= m) { 
                            enclosed = false;
                            continue;                            
                        }
                        if(vis[dy][dx]) continue;
                        if(grid[dy][dx] == 0) continue;
                        vis[dy][dx] = true;
                        q.push({dy, dx});
                    }
                }

                if(enclosed) ans += cells;
            }
        }
        return ans;
    }
};
