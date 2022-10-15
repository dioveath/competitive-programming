#include<bits/stdc++.h>

using namespace std;


void solve(int t){
  int m, n, p;
  cin >> m >> n >> p;

  vector<vector<int>> a = vector<vector<int>>(m, vector<int>(n));
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++) 
      cin >> a[i][j];

  int ans = 0;
  for(int i = 0; i < n; i++){
    int ms = -1;
    for(int j = 0; j < m; j++){
      if(a[j][i] == (p-1)) continue;
      ms = max(ms, a[j][i]);
    }

    if(a[p-1][i] < ms) ans += ms - a[p-1][i];
  }

  cout << "Case #" << t << ": " << ans << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
