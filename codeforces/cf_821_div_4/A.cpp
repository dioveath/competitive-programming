#include<bits/stdc++.h>

using namespace std;


void solve(int t){
  vector<int> A = vector<int>(3);
  for(int i = 0; i < 3; i++) cin >> A[i];
  sort(A.begin(), A.end());
  if(A[0] + A[1] == A[2]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
