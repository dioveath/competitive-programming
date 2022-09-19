#include<bits/stdc++.h>

using namespace std;


void solve(int t){
  int n;
  cin >> n;

  vector<pair<string, int>> col(n);
  vector<pair<int, int>> d(n);

  for(int i = 0; i < n; i++) {
    string a;
    int b, c;
    cin >> a >> b >> c;
    col[i] = {a, c};
    d[i] = {b, c};
  }

  sort(col.begin(), col.end());
  sort(d.begin(), d.end());

  int cnt = 0;
  for(int i = 0; i < n; i++){
    if(col[i].second == d[i].second) cnt++;
  }
    
  
  cout << "Case #" << t << ": " << cnt << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
