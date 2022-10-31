#include<bits/stdc++.h>

using namespace std;


void solve(int t){
  int n;
  cin >> n;

  vector<int> A = vector<int>(n);
  for(int i = 0; i < n; i++)
    cin >> A[i];

  sort(A.begin(), A.end());
  for(int i = 0; i < n-1; i++) {
    if(A[i] == A[i+1]) {
      cout << "NO" << endl;
      return;
    }    
  }

  cout << "YES" << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
