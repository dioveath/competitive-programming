// 130. Surrounded Regions
// Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
// A region is captured by flipping all 'O's into 'X's in that surrounded region.
// Example 1:


// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
// Explanation: Notice that an 'O' should not be flipped if:
// - It is on the border, or
// - It is adjacent to an 'O' that should not be flipped.
// The bottom 'O' is on the border, so it is not flipped.
// The other three 'O' form a surrounded region, so they are flipped.
// Example 2:

// Input: board = [["X"]]
// Output: [["X"]]
 

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 200
// board[i][j] is 'X' or 'O'.

class Solution {
public:
    int dir_x[4] = {1, -1, 0, 0};
    int dir_y[4] = {0, 0, 1, -1};
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'X') continue;
                vector<vector<bool>> vdp(board.size(), vector<bool>(board[0].size(), false));
                if(flip(board, i, j, vdp)){
                    for(int m = 0; m < vdp.size(); m++){
                        for(int n = 0; n < vdp[m].size(); n++){
                            if(vdp[m][n]) board[m][n] = 'X';
                        }
                    }
                }
            }
        }
    }
    
    bool flip(vector<vector<char>>& board, int y, int x, vector<vector<bool>>& vdp){        
        vdp[y][x] = true;
        bool ans = true;
        for(int k = 0; k < 4; k++){
            int dx = x + dir_x[k];
            int dy = y + dir_y[k];            
            if(dx < 0 || dy < 0 || dx >= board[y].size() || dy >= board.size()) return false;
            if(vdp[dy][dx] || board[dy][dx] == 'X') continue;                        
            ans = ans && flip(board, dy, dx, vdp);
        }
        return ans;
    }
};
