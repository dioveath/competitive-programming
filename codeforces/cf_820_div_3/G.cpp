#include<bits/stdc++.h>

using namespace std;


void solve(int t){
  string s, ts;
  cin >> s >> ts;

  if(s.length() < ts.length()) {
    cout << 0 << " " << 0 << endl;
    return;
  }

  int cnt = 0;
  
  for(int i = ts.length()-1; i < s.length(); i++){
    string chk = s.substr(i-(ts.length()-1), ts.length());
    if(chk == ts) cnt++;
  }

  cout << cnt << " " << cnt * cnt << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
