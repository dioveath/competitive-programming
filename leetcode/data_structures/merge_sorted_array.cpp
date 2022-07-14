// 88. Merge Sorted Array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        int mIndex = 0, nIndex = 0;
        for(int i = 0; i < m+n; i++){
            if(mIndex >= m) { 
                temp.push_back(nums2[nIndex++]);
                continue;
            }
            if(nIndex >= n) { 
                temp.push_back(nums1[mIndex++]);
                continue;
            }
            
            if(nums1[mIndex] < nums2[nIndex]){ 
                temp.push_back(nums1[mIndex++]);
            } else { 
                temp.push_back(nums2[nIndex++]);
            }
        }
        
        for(int i = 0; i < m+n; i++) {
            nums1[i] = temp[i];
        }
    }
};



// Small & Fast Solution
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m+n-1; m--; n--;
        while(m >= 0 && n >= 0)
            nums1[i--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
        while(n >= 0)
            nums1[i--] = nums2[n--];
    }
};
