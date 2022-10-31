// 1293. Shortest Path in a Grid with Obstacles Elimination
// You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.
// Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

// Example 1:
// Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
// Output: 6
// Explanation: 
// The shortest path without eliminating any obstacle is 10.
// The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
// Example 2:

// Input: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
// Output: -1
// Explanation: We need to eliminate at least two obstacles to find such a walk.

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 40
// 1 <= k <= m * n
// grid[i][j] is either 0 or 1.
// grid[0][0] == grid[m - 1][n - 1] == 0


class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();  
        
        vector<vector<bool>> vs(m, vector<bool>(n, false));
        vector<vector<vector<int>>> dp(m, vector(n, vector(k+1, -1)));
        int min = bfs(grid, vs, m-1, n-1, k, dp);
        
        if(min == INT_MAX) return -1;
        return min;
    }

    int bfs(vector<vector<int>>& grid, 
            vector<vector<bool>>& vs, 
            int y, int x, int k,
            vector<vector<vector<int>>>& dp
           ){
        int m = grid.size(), n = grid[0].size();
        if(x < 0 || x >= n || y < 0 || y >= m || vs[y][x]) return INT_MAX;        
        if(dp[y][x][k] != -1) return dp[y][x][k];        
        if(y == 0 && x == 0) return dp[y][x][k] = 0;        
        if(grid[y][x] == 1 && --k < 0) return INT_MAX;                
        
        vs[y][x] = true;
        int hor = min(bfs(grid, vs, y, x+1, k, dp), bfs(grid, vs, y, x-1, k, dp));
        int ver = min(bfs(grid, vs, y+1, x, k, dp), bfs(grid, vs, y-1, x, k, dp));
        vs[y][x] = false;
        
        int step = min(hor, ver);
        if(step != INT_MAX) step++;
        
        return dp[y][x][k] = step;
    }
    
};



// NOTE: This problem sucked me, I still don't know how the solution works
// FIXME: Fix my brain
// class Solution {
// public:
//     int shortestPath(vector<vector<int>>& grid, int k) {
//         // grid m x n
//         // gird[i] = 0 | 1
//         // can move up, down, left, right in one step
        
//         // return minimum number of steps to (m-1, n-1), if you can remove k obstacles at most
//         // if not possible return -1;
        
//         // how can path be blocked ??
//         // if we can dfs from one end to another?? 
//         // i.e. from 0 to m in y-direction || from 0 to n in x-direction
        
//         // what i know,
//         // shortest distance without obstacle is, m+n-2
//         // to reach obstacle i need to move right m times & down n times
//         // 

//         // brute-force solution O(N^2 + )
//         // for every permutation of obstacles 
//         // remove k number of obstacles
//         // then dfs the grid then store the minimum path
//         // return the minimum path
        
//         // understanding,
//         // for i to m:
//         //     for j to n:
//         //         if(dp[i-1][j] == -1 && dp[i][j-1] == -1) return -1;
//         //         int min = min(dp[i-1][j], dp[i][j-1])
//         //         dp[i,j] = min

//         int m = grid.size(), n = grid[0].size();
//         vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
                
//         for(int i = 1; i <= m; i++){
//             for(int j = 1; j <= n; j++){                
//                 if(grid[i-1][j-1] == 1) { 
//                     dp[i][j] = -1;
//                     continue;
//                 }
//                 // if(grid[i-1][j] == -1 && dp[i][j-1] == -1) return -1;
                

//                 if(i == 1 && j == 1) continue;
//                 dp[i][j] = max(dp[i-1][j], dp[i][j-1])+1;
//             }
//         }
        
//         for(int i = 0; i <= m; i++){
//             for(int j = 0; j <= n; j++){
//                 cout << dp[i][j] << "    ";
//             }
//             cout << endl;
//         }
//         cout << endl << endl;

	
        
//         return dp[m][n];
//     }
// };

// class Solution {
// public:
//     int shortestPath(vector<vector<int>>& grid, int k) {
//         // [0, 0, 0]
//         // [0, 1, 0]
//         // [0, 0, 0]
//         // [0, 1, 1]
//         // [0, 0, 0]
        
        
//         int m = grid.size(), n = grid[0].size();
//         vector<int> ver_vect(n), hor_vect(m);
        
//         for(int i = 0; i < m; i++){
//             int obs_cnt = 0;
//             for(int j = 0; j < n; j++) 
//                 obs_cnt += grid[i][j] == 1;
//             hor_vect[i] = obs_cnt;
//         }
        
//         for(int i = 0; i < n; i++){
//             int obs_cnt = 0;
//             for(int j = 0; j < m; j++) 
//                 obs_cnt += grid[j][i] == 1;
//             ver_vect[i] = obs_cnt;
//         }

//         int min_obs_path = INT_MAX;
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 int hor_cnt = hor_vect[i];
//                 if(i == 0) hor_cnt = hor_vect[m-1];
//                 if(i == m-1) hor_cnt = hor_vect[0];
//                 min_obs_path = min(min_obs_path, max(hor_cnt, ver_vect[j]));
//             }
//         }        
        
//         cout << min_obs_path << endl;
        
//         return m+n-2;
//         if(min_obs_path > k) return -1;
//         else return m+n-2;
//     }
// };


// class Solution {
// public:
//     int shortestPath(vector<vector<int>>& grid, int k) {
//         int m = grid.size(), n = grid[0].size();        

//         bool *vs;        
//         memset(vs, 0, m*n*sizeof(bool));
        
//         int min = bfs(grid, vs, 0, 0, k, 0);
//         if(min == INT_MAX) return -1;
//         return min;
//     }

//     int bfs(vector<vector<int>>& grid, bool* vs, int y, int x, int k, int step){
//         int m = grid.size(), n = grid[0].size();
//         if(y == m-1 && x == n-1) return step;
//         if(x < 0 || x >= n || y < 0 || y >= m) return INT_MAX;
//         if(*(vs+y*m+x)) return INT_MAX;
//         if(grid[y][x] == 1) k--;
//         if(k < 0) return INT_MAX;        
//         *(vs+y*m+x) = true;
        
//         int hor = min(bfs(grid, vs, y, x+1, k, step+1), bfs(grid, vs, y, x-1, k, step+1));
//         int ver = min(bfs(grid, vs, y+1, x, k, step+1), bfs(grid, vs, y-1, x, k, step+1));
        
//         return min(hor, ver);
//     }
    
    
// };



