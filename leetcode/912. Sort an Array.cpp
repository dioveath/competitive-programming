// 912. Sort an Array
// Given an array of integers nums, sort the array in ascending order and return it.
// You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

// Example 1:
// Input: nums = [5,2,3,1]
// Output: [1,2,3,5]
// Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

// Example 2:
// Input: nums = [5,1,1,2,0,0]
// Output: [0,0,1,1,2,5]
// Explanation: Note that the values of nums are not necessairly unique.
 
// Constraints:
// 1 <= nums.length <= 5 * 104
// -5 * 104 <= nums[i] <= 5 * 104

class Solution {
public:
  vector<int> sortArray(vector<int>& nums) {
    return mergeSort(nums);
  }

  vector<int> mergeSort(vector<int> nums){
    if(nums.size() == 0) return {};
    if(nums.size() == 1) return nums;

    int half = nums.size()/2;
    vector<int> leftPart;
    vector<int> rightPart;
    for(int i = 0; i < nums.size(); i++){
      if(i < half) leftPart.push_back(nums[i]);
      else rightPart.push_back(nums[i]);
    }

    vector<int> sortedLeft = mergeSort(leftPart);
    vector<int> sortedRight = mergeSort(rightPart);
    vector<int> sorted;
    int i = 0, j = 0;
    while(i < sortedLeft.size() && j < sortedRight.size()){
      if(sortedLeft[i] < sortedRight[j]){
	sorted.push_back(sortedLeft[i]);
	i++;
      } else {
	sorted.push_back(sortedRight[j]);
	j++;
      }
    }
    while(i < sortedLeft.size()) sorted.push_back(sortedLeft[i++]);
    while(j < sortedRight.size()) sorted.push_back(sortedRight[j++]);
    return sorted;
  }
    

};
