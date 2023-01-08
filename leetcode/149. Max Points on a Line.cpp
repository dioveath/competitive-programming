// 149. Max Points on a Line
// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.
// Example 1:


// Input: points = [[1,1],[2,2],[3,3]]
// Output: 3
// Example 2:


// Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
// Output: 4
 

// Constraints:

// 1 <= points.length <= 300
// points[i].length == 2
// -104 <= xi, yi <= 104
// All the points are unique.

class Solution {
public:
    double slope(int y2, int y1, int x2, int x1){
        if(x2 - x1 == 0) return INT_MAX;
        return (y2 - y1) / (double)(x2 - x1);
    }

    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 0; i < points.size(); i++){
            unordered_map<string, int> umap;
            for(int j = i+1; j < points.size(); j++){
                double m = slope(points[j][1], points[i][1], points[j][0], points[i][0]);
                double c = points[i][1] - m * (long long)points[i][0];

                if(m == -0 || m == 0) m = 0;
                string eq = to_string(m) + to_string(c);
                umap[eq]++;
                if(umap[eq] > ans) ans = umap[eq];
            }
        }
        return ans+1;
    }
};
