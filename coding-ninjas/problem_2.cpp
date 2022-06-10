// You are given an array of integers ARR[] of size N consisting of zeros and ones. You have to select a subset and flip bits of that subset. You have to return the count of maximum one’s that you can obtain by flipping chosen sub-array at most once.
// A flip operation is one in which you turn 1 into 0 and 0 into 1.
// For Example:
// If you are given an array {1, 1, 0, 0, 1} then you will have to return the count of maximum one’s you can obtain by flipping anyone chosen sub-array at most once, so here you will clearly choose sub-array from the index 2 to 3 and then flip it's bits. So, the final array comes out to be {1, 1, 1, 1, 1} which contains five ones and so you will return 5.
// Input Format :
// The first line of input consists of a single integer T denoting the total number of the test case.

// The first line of each test case contains an integer N, which represents the array's size.

// The second line of each test case contains N space-separated integers representing the array elements accordingly.
// Output Format :
// For each test case, return a single integer representing the maximum number of 1's you can have in the array after at most one flip operation.
// Note:
// You don’t have to print anything; it has already been taken care of. Just implement the given function. 
// Constraints:
// 1 <= T = 100
// 1 <= N <= 10^4
// 0 <= ARR[i] <= 1

// Time Limit: 1 sec
// Sample Input 1 :
// 3
// 5
// 1 0 0 1 0
// 4
// 1 1 1 0
// 5
// 0 0 1 0 0
// Sample Output 1 :
// 4
// 4
// 4
#include <iostream>

using namespace std;

int flipBits(int* arr, int n) 
{
  // Actually, we want to consider subarray to maximize the differences between the count of ones & zeros
  // if we change 1s to -1 and change 0 to 1, the sum of values will give us the maximum difference
  // between the counts(MAX). So, we have to find a subarray with the maximum sum, which can be done
  // by Kadane's algorithm. Finally, we return MAX + count of ones array

  int max = 0;
  int current_max = 0;
  int ones_count = 0;
  for(int i = 0; i < n; i++){
    int val = arr[i] == 1 ? -1 : 1;
    current_max = (current_max + val > val ? current_max + val : val);
    ones_count += arr[i] ? 1 : 0;
    if(current_max > max){
      max = current_max;
    }
  }
  return max + ones_count;
}


int test[5] = { 1, 0, 0, 1, 0 };

int main(){
  cout << flipBits(test, 5);

  return 0;
}
