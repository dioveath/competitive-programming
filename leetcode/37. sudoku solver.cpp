// 37. Sudoku Solver
// Write a program to solve a Sudoku puzzle by filling the empty cells.
// A sudoku solution must satisfy all of the following rules:
// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

// Example 1:
// Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
// Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
// Explanation: The input board is shown above and the only valid solution is shown below:

// Constraints:

// board.length == 9
// board[i].length == 9
// board[i][j] is a digit or '.'.
// It is guaranteed that the input board has only one solution.



class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
    
    bool backtrack(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.') continue;
                
                vector<char> poss = get_possibles(board, i, j);
                for(int k = 0; k < poss.size(); k++){
		    board[i][j] = poss[k];
		    if(backtrack(board)) return true;
		    else board[i][j] = '.';
                }
                
		return false;
            }
        }
	return true;
    }
    
    vector<char> get_possibles(vector<vector<char>>& board, int y, int x){
        vector<char> poss = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; 
        for(int i = 0; i < 9; i++){
            auto it = find(poss.begin(), poss.end(), board[y][i]);
            if(it != poss.end()) poss.erase(it);
            
            it = find(poss.begin(), poss.end(), board[i][x]);
            if(it != poss.end()) poss.erase(it);
            
            int offx = floor(x/3);
            int offy = floor(y/3);
            char val = board[offy * 3 + floor(i/3)][offx * 3 + i%3];
            
            it = find(poss.begin(), poss.end(), val);
            if(it != poss.end()) poss.erase(it);
        }
        return poss;
    }
    
};
