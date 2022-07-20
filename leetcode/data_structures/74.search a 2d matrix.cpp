// 74. Search a 2D Matrix
// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// Example 1:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
// Example 2:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false
// Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int right = (matrix.size() * matrix[0].size()) - 1;
        int left = 0;
        while(left <= right){
            int mid = (left + right)/2;
            int value = matrix[mid/matrix[0].size()][mid%matrix[0].size()];
            int leftValue = matrix[left/matrix[0].size()][left%matrix[0].size()];
            int rightValue = matrix[right/matrix[0].size()][right%matrix[0].size()];
            
            if(value == target) return true;
            if(leftValue == target) return true;
            if(rightValue == target) return true;
            
            if(target > value) left = mid+1;
            else right = mid - 1;
                        
        }
        return false;
    }
};
