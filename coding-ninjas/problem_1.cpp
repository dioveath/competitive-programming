#include <bits/stdc++.h>
#include <iostream>

using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    int currentMax = 0;
    int maxCounter = 0;
    for(int i = 0; i < n; i++){
        maxCounter += arr[i];
        
        if(maxCounter > currentMax) { 
            currentMax = maxCounter;
        }
        if(maxCounter < 0) maxCounter = 0;
    }
    return currentMax;
}


// int test[10] = {
//   1, 2, 7, -4, 3, 2, -10, 9, 1
// };

int test[10] = { 1, 2, 7, -4, 3, 2, -10, 9, 1 };


int main(){
  cout << maxSubarraySum(test, 10);

  return 0;
}
