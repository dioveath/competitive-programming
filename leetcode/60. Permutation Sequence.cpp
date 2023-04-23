// 60. Permutation Sequence
// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

// Example 1:

// Input: n = 3, k = 3
// Output: "213"
// Example 2:

// Input: n = 4, k = 9
// Output: "2314"
// Example 3:

// Input: n = 3, k = 1
// Output: "123"
 

// Constraints:

// 1 <= n <= 9
// 1 <= k <= n!


class Solution {
public:
    string getPermutation(int n, int k) {
        string nums;
        for(int i = 0; i < n; i++) 
            nums += ('0'+i+1);
        k--;
        while(k--){
            for(int i = n-1; i >= 0; i--){
                if(i == 0 || nums[i-1] < nums[i]){
                    if(i == 0) swap(nums[i], nums[n-1]);
                    else {
                        int minI = i;
                        for(int j = i; j < n; j++){
                            if(nums[j] > nums[i-1] && nums[j] < nums[minI]) minI = j;
                        }
                        swap(nums[i-1], nums[minI]);
                    }
                    sort(nums.begin()+i, nums.end());
                    break;
                }
            }
        }
        return nums;
    }
};
