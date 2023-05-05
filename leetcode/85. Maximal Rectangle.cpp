// 85. Maximal Rectangle
// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
// Example 1:


// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Example 2:

// Input: matrix = [["0"]]
// Output: 0
// Example 3:

// Input: matrix = [["1"]]
// Output: 1
 

// Constraints:

// rows == matrix.length
// cols == matrix[i].length
// 1 <= row, cols <= 200
// matrix[i][j] is '0' or '1'.


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> left(n, 0), right(n, n), height(n, 0);
        
        int ans = 0;
        for(int i = 0; i < m; i++){
            int cur_left = 0, cur_right = n;
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }

            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1') left[j] = max(left[j], cur_left);
                else { left[j] = 0; cur_left = j+1; }
            }

            for(int j = n-1; j >= 0; j--){
                if(matrix[i][j] == '1') right[j] = min(right[j], cur_right);
                else { right[j] = n; cur_right = j; }
            }

            for(int j = 0; j < n; j++){
                ans = max(ans, (right[j] - left[j]) * height[j]);
            }
        }

        return ans;
    }
};