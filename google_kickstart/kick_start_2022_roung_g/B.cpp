#include<bits/stdc++.h>

using namespace std;


void solve(int t){
  int rs, sh;
  cin >> rs >> sh;

  int comp = (rs+sh) * (rs+sh);  
  vector<pair<double, int>> balls;

  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    int dist = x * x + y * y;
    if(dist <= comp) balls.push_back({dist, 0});
  }

  int m;
  cin >> m;
  vector<vector<int>> b(m, vector<int>(2));
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    int dist = x * x + y * y;
    if(dist <= comp) balls.push_back({dist, 1});    
  }

  if(balls.size() == 0) {
    cout << "Case #" << t << ": " << 0 << " " << 0 << endl;
    return;
  }

  sort(balls.begin(), balls.end());

  vector<int> ans(2, 0);
  int winner = balls[0].second;
  ans[balls[0].second]++;

  int prev = balls[0].first;
  for(int i = 1; i < balls.size(); i++){
    if(winner != balls[i].second) break;
    if(prev == balls[i].first) break;

    prev = balls[i].first;
    ans[balls[i].second]++;
  }

  cout << "Case #" << t << ": " << ans[0] << " " << ans[1] << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
