#include<bits/stdc++.h>


using namespace std;


void solve(int t){
  int N, R, C, r, c;
  cin >> N >> R >> C >> r >> c;

  string str;
  cin >> str;

  vector<vector<bool>> dp(R, vector<bool>(C, false));

  r--; c--;
  dp[r][c] = true;

  for(int i = 0; i < N; i++){
    switch(str[i]){
    case 'N':
      while(r > 0 && dp[--r][c]);
      dp[r][c] = true;
      break;
    case 'S':
      while(r < R-1 && dp[++r][c]);
      dp[r][c] = true;
      break;
    case 'E':
      while(c < C-1 && dp[r][++c]);
      dp[r][c] = true;
      break;
    case 'W':
      while(c > 0 && dp[r][--c]);
      dp[r][c] = true;
      break;
    }
  }


  cout << "Case #" << t << ": " << r+1 << " " << c+1 << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
