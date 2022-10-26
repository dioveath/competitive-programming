#include<bits/stdc++.h>

using namespace std;


inline int fact(int n) {
  int fact = 1;
  for(int i = 2; i <= n; i++) fact *= i;
  return fact;
}

inline int comb(int n, int k){
  return fact(n) / (fact(k) * fact(n-k));
}


void solve(int t){
  int n;
  cin >> n;

  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];

  cout << comb(10-n, 2) * comb(4, 2) << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
