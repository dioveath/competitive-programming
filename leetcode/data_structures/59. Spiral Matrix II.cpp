// 59. Spiral Matrix II

// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
// Example 1:

// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]
// Example 2:

// Input: n = 1
// Output: [[1]]
 

// Constraints:

// 1 <= n <= 20


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int dir_x[4] = {1, 0, -1, 0};
        int dir_y[4] = {0, 1, 0, -1};
        int val = 1;
        
        int y = 0, x = 0, k = 0;
        res[y][x] = val++;
        while(val <= n * n){
            y += dir_y[k % 4];
            x += dir_x[k % 4];

            if(x < 0 || y < 0 || x >= n || y >= n || res[y][x]) { 
                y -= dir_y[k%4];
                x -= dir_x[k%4];
                k++;                
                continue;
            }
            res[y][x] = val++;                         
        }
        return res;
    }
};
