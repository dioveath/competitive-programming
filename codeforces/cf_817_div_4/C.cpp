#include<bits/stdc++.h>


using namespace std;


void solve(int t){
  int n;
  cin >> n;

  vector<vector<string>> s(3, vector<string>(n));
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < n; j++)
      cin >> s[i][j];

  int p[3] = {0};

  unordered_map<string, int> m1, m2, m3;
  for(int j = 0; j < n; j++){
    m1[s[0][j]]++;
    m2[s[1][j]]++;
    m3[s[2][j]]++;
  }

  for(int k = 0; k < n; k++){
    if(m2[s[0][k]] && m3[s[0][k]]) continue;
    if(m2[s[0][k]] || m3[s[0][k]]) p[0]++;
    else p[0] += 3;
  }

  for(int k = 0; k < n; k++){
    if(m1[s[1][k]] && m3[s[1][k]]) continue;
    if(m1[s[1][k]] || m3[s[1][k]]) p[1]++;
    else p[1] += 3;
  }

  for(int k = 0; k < n; k++){
    if(m1[s[2][k]] && m2[s[2][k]]) continue;
    if(m1[s[2][k]] || m2[s[2][k]]) p[2]++;
    else p[2] += 3;
  }    


  cout << p[0] << " " << p[1] << " " << p[2] << endl;

}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
