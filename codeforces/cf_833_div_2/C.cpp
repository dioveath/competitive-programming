#include<bits/stdc++.h>

using namespace std;


void solve(int t){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  int ans1 = 0, ans2 = 0, sum = 0;
  for(int i = n-1; i >= 0; i--) {
    if(a[i] == 0) {
      ans1++;
      sum = 0;
    } else {
      sum += a[i];
      if(sum == 0) {
	ans1++;
      }
    }
  }

  sum = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] == 0) {
      ans2++;
      sum = 0;
    } else {
      sum += a[i];
      if(sum == 0) {
	ans2++;
      }
    }
  }  

  cout << max(ans1, ans2) << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
    
