// 1091. Shortest Path in Binary Matrix
// Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.
// Example 1:


// Input: grid = [[0,1],[1,0]]
// Output: 2
// Example 2:


// Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
// Output: 4
// Example 3:

// Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
// Output: -1
 

// Constraints:

// n == grid.length
// n == grid[i].length
// 1 <= n <= 100
// grid[i][j] is 0 or 1


class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]) return -1;        
        queue<pair<int, int>> q({{0, 0}});
        int dir_y[8] = {0,  0, 1,-1, -1, -1, 1, 1};
        int dir_x[8] = {1, -1, 0, 0, -1,  1, 1,-1};
        int dist = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pair<int, int> pos = q.front();
                q.pop();
                
                if(pos.first == grid.size()-1 && 
                   pos.second == grid[0].size()-1) return dist+1;
                
                for(int i = 0; i < 8; i++){
                    int dx = pos.second + dir_x[i];
                    int dy = pos.first + dir_y[i];
                    if(dx < 0 || dx >= grid[0].size() || dy < 0 || dy >= grid.size()) continue;
                    if(grid[dy][dx]) continue;
                    grid[dy][dx] = 1;
                    q.push({dy,dx});
                }
                
            }
            dist++;
        }
        return -1;
    }
};
