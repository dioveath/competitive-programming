#include<bits/stdc++.h>

using namespace std;


void solve(int t){
  int n;
  cin >> n;

  vector<int> a(n);
  for(int i = 0; i < n; i++)
    cin >> a[i];

  int ans = 0;
  for(int i = 0; i < n; i++){
    ans = max(ans, a[i]-a[0]);
    ans = max(ans, a[n-1]-a[i]);    
    ans = max(ans, a[(n-1+i)%n]-a[i]);
  }

  cout << ans << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
