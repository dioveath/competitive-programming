// 350. Intersection of Two Arrays II
// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

// Example 1:
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, bool> hashmap;
        
        for(int i = nums1.size()-1; i >= 0; i--) { 
            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]) {
                    result.push_back(nums1[i]);                                         
                    nums1.erase(nums1.begin()+i);
                    nums2.erase(nums2.begin()+j);
                    break;
                } 
            }
        }
        return result;
    }
};


// Fast solution
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashmap;
        vector<int> result;
        
	    for(auto x: nums1)
	        hashmap[x]++;
        
	    for(auto y: nums2)
	        if(hashmap[y]-- > 0) result.push_back(y);
            
        return result;
    }
};
