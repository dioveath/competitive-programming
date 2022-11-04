// 51. N-Queens
// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

// Example 1:
// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
// Example 2:

// Input: n = 1
// Output: [["Q"]]
 
// Constraints:

// 1 <= n <= 9


class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> rows = {};
        vector<bool> cols = vector(n, false);
        set<int> neg_diag, pos_diag;
        backtrack(n, 0, n, cols, neg_diag, pos_diag, rows);
        return ans;
    }

    void backtrack(int n, int y, int k, 
    vector<bool>& cols, 
    set<int>& neg_diag, 
    set<int>& pos_diag, 
    vector<string>& rows){
        if(k == 0) ans.push_back(rows);
        if(y >= n) return;

        string row = "";
        int i = 0; 
        while(i++ < n) row += '.';

        for(int j = 0; j < n; j++){
            if(cols[j]) continue;
            if(neg_diag.find(j-y) != neg_diag.end()) continue;
            if(pos_diag.find(j+y) != pos_diag.end()) continue;

            cols[j] = true;
            row[j] = 'Q';
            neg_diag.insert(j-y);
            pos_diag.insert(j+y);
            rows.push_back(row);

            backtrack(n, y+1, k-1, cols, neg_diag, pos_diag, rows);

            cols[j] = false;
            row[j] = '.';
            neg_diag.erase(j-y);
            pos_diag.erase(j+y);
            rows.pop_back();
        }
    }

};













