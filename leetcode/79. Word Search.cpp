// 79. Word Search
// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
// Example 1:

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
// Example 2:

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true
// Example 3:

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false

// Constraints:
// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board and word consists of only lowercase and uppercase English letters.
 
// Follow up: Could you use search pruning to make your solution faster with a larger board?

class Solution {
public:
    int dir_x[4] = {0, 0, 1, -1};
    int dir_y[4] = {1, -1, 0, 0};    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] != word[0]) continue;
                if(dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string word, int y, int x, int k){
        if(k+1 == word.length()) return true;
        char c = board[y][x];
        board[y][x] = '*';
        
        bool ans = false;
        for(int d = 0; d < 4; d++){
            int dx = dir_x[d] + x;
            int dy = dir_y[d] + y;
            if(dx < 0 || dx >= board[0].size() || dy < 0 || dy >= board.size()) continue;
            if(board[dy][dx] == word[k+1]) ans |= dfs(board, word, dy, dx, k+1);
        }
        
        board[y][x] = c;
        return ans;
    }
};
