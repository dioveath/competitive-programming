// 56. Merge Intervals
// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

// Constraints:

// 1 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti <= endi <= 104


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
             [](const vector<int> &a, const vector<int> &b) -> bool
             { 
                return a[0] < b[0];
             });
        
        vector<vector<int>> res;
        vector<int> s = intervals[0];
        int n = intervals.size();
                
        for(int i = 1; i < n; i++){
            if(s[1] < intervals[i][0] || intervals[i][1] < s[0]) {
                res.push_back({s[0], s[1]});
                s = intervals[i];
            }
            s[0] = min(s[0], intervals[i][0]);
            s[1] = max(s[1], intervals[i][1]);
        }
        res.push_back({s[0], s[1]});
        return res;
    }
};
