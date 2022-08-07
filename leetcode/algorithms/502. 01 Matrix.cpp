// 542. 01 Matrix
// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
// The distance between two adjacent cells is 1.
// Example 1:
// Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
// Output: [[0,0,0],[0,1,0],[0,0,0]]
// Example 2:
// Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
// Output: [[0,0,0],[0,1,0],[1,2,1]]
// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 104
// 1 <= m * n <= 104
// mat[i][j] is either 0 or 1.
// There is at least one 0 in mat.


class Solution {
public:

  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), 100000));    
        
    for(int i = 0; i < mat.size(); i++){
      for(int j = 0; j < mat[0].size(); j++){
	if(mat[i][j] == 0) { dp[i][j] = 0; continue; }
	if(i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);                
	if(j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
      }
    }
        
    for(int i = mat.size() - 1; i >= 0; i--){
      for(int j = mat[0].size() - 1; j >= 0; j--){
	if(mat[i][j] == 0) { dp[i][j] = 0; continue; }
	if(i < mat.size() - 1) dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);                
	if(j < mat[0].size() - 1) dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
      }
    }
        
    return dp;
  }
    
};

