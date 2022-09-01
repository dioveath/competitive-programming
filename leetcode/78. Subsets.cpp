// 78. Subsets

class Solution {
public:
    unordered_set<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.insert({});
        backtrack(nums, 0, {});
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
    
    void backtrack(vector<int> nums, int i, vector<int> curr){
        if(i >= nums.size()) return;
        while(i < nums.size()){
            vector<int> temp = curr;
            temp.push_back(nums[i]);
            res.insert(temp);
            backtrack(nums, i+1, temp);
            i++;
        }
    }
};
