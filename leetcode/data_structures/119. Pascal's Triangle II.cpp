// 119. Pascal's Triangle II
// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
// Example 1:

// Input: rowIndex = 3
// Output: [1,3,3,1]
// Example 2:

// Input: rowIndex = 0
// Output: [1]
// Example 3:

// Input: rowIndex = 1
// Output: [1,1]
 

// Constraints:

// 0 <= rowIndex <= 33
 
// Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        return recurse(rowIndex);
    }
    
    vector<int> recurse(int rowIndex){        
        if(rowIndex == 0) return {1};
        if(rowIndex == 1) return {1, 1};

        vector<int> prev = recurse(rowIndex-1);
        vector<int> res = prev;
        
        res.push_back(1);
        for(int i = 1; i <= res.size()/2; i++){
            if(!(i == res.size()/2 && res.size() % 2 == 0))
                res[i] = prev[i] + prev[i-1];
            res[res.size()-1-i] = res[i];                        
        }
                        
        return res;
    }
};

