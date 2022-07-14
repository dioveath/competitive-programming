// 217. Contains Duplicate
// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
// Example 1:

// Input: nums = [1,2,3,1]
// Output: true

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> umap; 
        for(int i = 0; i < nums.size(); i++){
            if(umap.find(nums[i]) == umap.end())
                umap.insert(pair<int, int>(nums[i], 1));
            else 
                return true;
        }
        return false;
    }
};
