#include<bits/stdc++.h>

using namespace std;

void solve(int t){
  int n, k;
  cin >> n >> k;

  vector<int> ans(n);
  for(int i = 0; i < n; i++)
    ans[i] = i+1;

  for(int i = 0; i < (n/2); i++)
    cout << ans[n-(i+1)] << " " << ans[i] << " ";


  if(n % 2 != 0) {
    cout << (n/2)+1 <<  " ";
  }

  cout << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
