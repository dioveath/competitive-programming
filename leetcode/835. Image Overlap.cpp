// 835. Image Overlap
// You are given two images, img1 and img2, represented as binary, square matrices of size n x n. A binary matrix has only 0s and 1s as values.
// We translate one image however we choose by sliding all the 1 bits left, right, up, and/or down any number of units. We then place it on top of the other image. We can then calculate the overlap by counting the number of positions that have a 1 in both images.
// Note also that a translation does not include any kind of rotation. Any 1 bits that are translated outside of the matrix borders are erased.
// Return the largest possible overlap.

// Example 1:
// Input: img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
// Output: 3
// Explanation: We translate img1 to right by 1 unit and down by 1 unit.

// The number of positions that have a 1 in both images is 3 (shown in red).
// Example 2:

// Input: img1 = [[1]], img2 = [[1]]
// Output: 1
// Example 3:

// Input: img1 = [[0]], img2 = [[0]]
// Output: 0
 
// Constraints:

// n == img1.length == img1[i].length
// n == img2.length == img2[i].length
// 1 <= n <= 30
// img1[i][j] is either 0 or 1.
// img2[i][j] is either 0 or 1.



// NOTE:(Not a solution) See below for the solution
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        // [1, 1, 0]
        // [0, 1, 0]
        // [0, 1, 0]
        
        // [0, 0, 0]
        // [0, 1, 1]
        // [0, 0, 1]

        
        // 1st Solution: (Brute Force) O(n4) - O(1)
        // foreach i,j to img1.size(),img1[0].size()
        //   if i,j != 1 continue
        //   foreach m,n to img2.size(),img2[0].size()
        //     if m,n != 1 continue
        //       max = dfs(img1, i, j, img2, m, n)
        //  return max
        
        // 2nd Solution: 
        // dir_x = {0, 0, -1, 1};
        // dir_y = {-1, 1, 0, 0};
        
        // vector<vector<int>> dmap;
        // for i to img1.size()
        //      for j to img2.size()
        //           if(img1[i,j] == 1) {
        //              dfs({
        //                  for k to 4
        //                  if img1[i+dir_x[k], j+dir_y[k]] == 1
        //                      dmap.push_back(k)
        //                      dfs
        //              })
        //              break;
        //           }
        //
        //
        // if(dmap.size()) return 0;
        // 
        // max_overlap = 0
        // for i to img2.size()
        //      for j to img2.size()
        //             if img i,j == 1
        //                  dmap_idx = 0
        //                  overlap
        //                  dfs ({
        //                      for k to 4
        //                      if(img1[i+dir[k], j+dir_y[k]] == 1 && k == dmap_idx) overlap++;
        //                  })
        //                  max_overlap = max(overlap, max_overlap)

      
    }
};


class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        
        int max_count = 0;
        vector<vector<int>> count(n*2, vector<int>(n*2, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){                
                if(img1[i][j] != 1) continue;
                for(int a = 0; a < n; a++){
                    for(int b = 0; b < n; b++){
                        if(img2[a][b] != 1) continue;
                        int off_y = a-i;                        
                        int off_x = b-j;
                        
                        max_count = max(++count[n+off_y][n+off_x], max_count);
                    }
                }
            }
        }
        return max_count;
    }
    
    
};
