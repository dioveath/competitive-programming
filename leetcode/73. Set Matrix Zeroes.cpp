// 73. Set Matrix Zeroes
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.
// Example 1:


// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
// Example 2:


// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

// Constraints:

// m == matrix.length
// n == matrix[0].length
// 1 <= m, n <= 200
// -231 <= matrix[i][j] <= 231 - 1
 

// Follow up:

// A straightforward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<pair<int, int>> z;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] != 0) continue;
                z.push_back({i, j});
            }
        }
        
        for(auto it : z){
            for(int i = 0; i < m; i++) matrix[i][it.second] = 0;
            for(int i = 0; i < n; i++) matrix[it.first][i] = 0;
        }
    }
};



// O(MxN) Time
// O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool col = matrix[0][0] == 0;
        bool row = matrix[0][0] == 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] != 0) continue;
                
                matrix[0][j] = 0;
                matrix[i][0] = 0;
                if(j == 0) col = true;
                if(i == 0) row = true;
            }
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++)
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        }

        if(col) for(int i = 0; i < m; i++) matrix[i][0] = 0;
        if(row) for(int j = 0; j < n; j++) matrix[0][j] = 0;
    }
};
