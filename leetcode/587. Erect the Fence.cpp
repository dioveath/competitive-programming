// 587. Erect the Fence
// You are given an array trees where trees[i] = [xi, yi] represents the location of a tree in the garden.
// You are asked to fence the entire garden using the minimum length of rope as it is expensive. The garden is well fenced only if all the trees are enclosed.
// Return the coordinates of trees that are exactly located on the fence perimeter.

// Example 1:


// Input: points = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
// Output: [[1,1],[2,0],[3,3],[2,4],[4,2]]
// Example 2:


// Input: points = [[1,2],[2,2],[4,2]]
// Output: [[4,2],[2,2],[1,2]]
 

// Constraints:

// 1 <= points.length <= 3000
// points[i].length == 2
// 0 <= xi, yi <= 100
// All the given points are unique.


// NOTE: Revise this more, 
class Solution { 
    public:
        vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        // Andrew's monotone chain method.
        sort(begin(points), end(points), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        // left to right
        const int n = size(points);
        vector<vector<int>> ans;
        ans.reserve(n);
        for (int i = 0; i < n; ++i) {
            while (size(ans) > 1 && orientation(ans[size(ans) - 2], ans.back(), points[i]) < 0) 
                ans.pop_back();
            ans.push_back(points[i]);
        }
        // If all points are along a line, size(ans) is n after left to right procedure.
        if (size(ans) == n) return ans;

        // right to left
        for (int i = n - 2; i >= 0; --i) {
            while (size(ans) > 1 && orientation(ans[size(ans) - 2], ans.back(), points[i]) < 0) 
                ans.pop_back();
            ans.push_back(points[i]);
        }
        ans.pop_back();
        return ans;
    }

    int orientation(const vector<int>& a, const vector<int>& b, const vector<int>& c) {
        return (b[0] - a[0]) * (c[1] - b[1]) - (b[1] - a[1]) * (c[0] - b[0]);
    }    
};
