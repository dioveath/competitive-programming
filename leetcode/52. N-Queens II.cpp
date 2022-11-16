// 52. N-Queens II
// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return the number of distinct solutions to the n-queens puzzle.

// Example 1:


// Input: n = 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
// Example 2:

// Input: n = 1
// Output: 1
 

// Constraints:
// 1 <= n <= 9

class Solution {
public:
    int ans = 0;
    int totalNQueens(int n) {
        set<int> posdiag, negdiag, rows;
        backtrack(negdiag, posdiag, rows, 0, n, 0);
        return ans;
    }

    void backtrack(set<int>& posdiag, set<int>& negdiag, set<int>& rows, int y, int n, int q){ 
        if(q == n) { ans++; return; }
        
        for(int i = 0; i < n; i++){
            if(posdiag.find(i+y) != posdiag.end()) continue;
            if(negdiag.find(i-y) != negdiag.end()) continue;
            if(rows.find(i) != rows.end()) continue;

            posdiag.insert(i+y);
            negdiag.insert(i-y);
            rows.insert(i);

            backtrack(posdiag, negdiag, rows, y+1, n, q+1);

            posdiag.erase(i+y);
            negdiag.erase(i-y);
            rows.erase(i);
        }

    }
};
