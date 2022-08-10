// 120. Triangle 
// Given a triangle array, return the minimum path sum from top to bottom.
// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

// Example 1:

// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
// Example 2:

// Input: triangle = [[-10]]
// Output: -10
 

// Constraints:

// 1 <= triangle.length <= 200
// triangle[0].length == 1
// triangle[i].length == triangle[i - 1].length + 1
// -104 <= triangle[i][j] <= 104
 

// Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?

class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        for(int i = t.size()-2; i >= 0; i--)
            for(int j = 0; j < t[i].size(); j++)
                t[i][j] += min(t[i+1][j], t[i+1][j+1]);
        return t[0][0];
    }
    
};



// FIXME: What's wrong in this solution?
class Solution {
public:
    long long dp[2000][2000];
    int minimumTotal(vector<vector<int>>& t) {
        for(int i = 0; i < 100; i++)
            for(int j = 0; j < 100; j++)
                dp[i][j] = -99999;
        return min_trav(t, 0, 0);
    }
    
    long long min_trav(vector<vector<int>> t, int idx, int idy){
        if(idy == t.size()) return 0;
        if(idx >= t[idy].size()) return INT_MAX;
        if(dp[idy][idx] != -99999) return dp[idy][idx];
        
        long long fmin = min_trav(t, idx, idy+1);
        long long smin = min_trav(t, idx+1, idy+1);
        
        long long res = t[idy][idx] + (fmin < smin ? fmin : smin);
        return dp[idy][idx] = res;
    }
};
