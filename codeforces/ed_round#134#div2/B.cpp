#include<bits/stdc++.h>


using namespace std;


void solve(int t){
  int n, m, sx, sy, d;
  cin >> n >> m >> sx >> sy >> d;

  vector<vector<bool>> dp(n, vector<bool>(m, false));
  int dir_x[5] = {1, -1, 0, 0, 0};
  int dir_y[5] = {0, 0, 1, -1, 0};

  queue<pair<int, int>> q({{--sy, --sx}});
  // if(!(sy < 0 || sy >= n || sx < 0 || sx >= m)) 
  //   dp[sy][sx] = true;

  cout << sy << sx << endl;

  while(!q.empty()){
    int sz = q.size();

    while(sz--) {
      pair<int, int> pos = q.front();
      q.pop();

      for(int i = 0; i < 5; i++){
	int dx = pos.first + dir_x[i];
	int dy = pos.second + dir_y[i];
	if(dy < 0 || dy >= n || dx < 0 || dx >= m) continue;
	if(dp[dy][dx]) continue;

	int dist = abs(sx - dx) + abs(sy - dy);
	if(dist <= d) {
	  q.push({dy, dx});
	  dp[dy][dx] = true;
	}
      }
    }

  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout << dp[i][j];
    }
    cout << endl;
  }

}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
