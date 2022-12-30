#include<bits/stdc++.h>

using namespace std;

void solve(int t){
  int n, m;
  cin >> n >> m;

  vector<int> a, b;
  for(int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }

  for(int i = 0; i < m; i++) {
    int tmp;
    cin >> tmp;
    b.push_back(tmp);
  }

  sort(a.begin(), a.end());
  for(int i = 0; i < m; i++){
    a[0] = b[i];
    sort(a.begin(), a.end());    
  }

  long long ans = 0;
  for(int i = 0; i < n; i++)
    ans += a[i];

  cout << ans << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
