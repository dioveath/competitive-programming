// 54. Spiral Matrix
// Given an m x n matrix, return all elements of the matrix in spiral order.

// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:


// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 
// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<int> ans;
        int l = 0, r = n-1;
        int t = 0, b = m-1;
        while(l <= r && t <= b){
            if(l > r) break;
            for(int i = l; i <= r; i++)
                ans.push_back(matrix[t][i]);
            t++;
            if(t > b) break;
            for(int i = t; i <= b; i++)
                ans.push_back(matrix[i][r]);
            r--;
            if(l > r) break;
            for(int i = r; i >= l; i--)
                ans.push_back(matrix[b][i]);
            b--;
            if(t > b) break;
            for(int i = b; i >= t; i--)
                ans.push_back(matrix[i][l]);
            l++;
        }

        return ans;
    }
};
