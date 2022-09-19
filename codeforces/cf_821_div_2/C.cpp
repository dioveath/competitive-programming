#include<bits/stdc++.h>

using namespace std;


void solve(int t){
  int n;
  vector<int> a(n);

  vector<pair<int,int>> ans;

  for(int i = 0; i < n; i++)
    cin >> a[i];

  for(int i = 0; i < n; i++){
    while(a[i] < a[i+1]) i++;
    if(i+1 < n && a[i] + a[i+1] % 2 == 0) {
      swap(a[i], a[i+1]);
      ans.push_back({i, i+1});
    }
  }


  cout << ans.size() << endl;
  for(auto it : ans){
    cout << it.first << it.second << endl;
  }
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
