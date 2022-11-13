#include<bits/stdc++.h>

using namespace std;


void solve(int t){
  int n;
  cin >> n;
  string s;
  cin >> s;

  int ans = 0;
  for(int i = 0; i < n; i++){
    int freq[10] = {0};
    int max_freq = 0, dist = 0;
    for(int j = i; j < n && j < i+100; j++){
      freq[s[j]-'0']++;
      if(freq[s[j]-'0'] == 1) dist++;

      max_freq = max(freq[s[j]-'0'], max_freq);
      if(max_freq <= dist) ans++;
    }
  }

  cout << ans << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
