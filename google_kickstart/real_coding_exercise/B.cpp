#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A) {
  sort(A.begin(), A.end());
  int sideA = 0, sideB = 0;
  for(int i = A.size()-1; i > 0; i--){
    if(A[i] == A[i-1]) {
      if(sideA == 0) { sideA = A[i--]; continue; }
      if(sideB == 0) { sideB = A[i--]; continue; }
      break;
    }
  }

  if(sideB == 0 || sideA == 0) return -1;
  return abs(sideB - sideA);
}

int main(){
  cout << solution({2,2,2,0}) << endl;
  cout << solution({911, 1, 3, 1000, 1000, 2, 2, 999, 1000, 911}) << endl;  
}
