class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sorted;
        int numsOneIndex = 0;
        int numsTwoIndex = 0;
        int numsOneSize = nums1.size();
        int numsTwoSize = nums2.size();
        while(true){
            if(numsOneIndex >= numsOneSize && numsTwoIndex >= numsTwoSize){
                break;
            }            
            
            if(numsOneIndex < numsOneSize && numsTwoIndex < numsTwoSize) { 
                if(nums1[numsOneIndex] > nums2[numsTwoIndex]) { 
                    sorted.push_back(nums2[numsTwoIndex]);
                    numsTwoIndex++;
                } else { 
                    sorted.push_back(nums1[numsOneIndex]);
                    numsOneIndex++;
                }
                continue;
            }
            
            if(numsOneIndex >= numsOneSize) { 
                sorted.push_back(nums2[numsTwoIndex]);
                numsTwoIndex++;
            } else { 
                sorted.push_back(nums1[numsOneIndex]);
                numsOneIndex++;
            }       
        }
            
        int size = sorted.size();   
        for(int i = 0; i < sorted.size(); i++)
            cout << sorted[i] << "|";
        if(size % 2 == 0) { 
            return (float)(sorted[size/2] + sorted[((size/2) - 1)])/(double)2.0;
        } else { 
            return sorted[size/2];
        }
    }
};
