// 240. Search a 2D Matrix II
// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.

// Example 1:
// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
// Output: true
// Example 2:


// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
// Output: false
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= n, m <= 300
// -109 <= matrix[i][j] <= 109
// All the integers in each row are sorted in ascending order.
// All the integers in each column are sorted in ascending order.
// -109 <= target <= 109

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++){
            int l = 0, r = matrix[0].size()-1;
            while(l <= r){
                int m = l+(r-l)/2;
                if(matrix[i][m] == target) return true;
                else if(matrix[i][m] > target) r = m-1;
                else l = m+1;
            }
        }
        return false;
    }
};


// O(log(m+n)) solution ??
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = 0, c = matrix[0].size()-1;
        while(c >= 0 && r <= matrix.size()-1){
            if(matrix[r][c] == target) return true;
            else if(target > matrix[r][c]) r++;
            else c--;
        }
        return false;
    }
};
