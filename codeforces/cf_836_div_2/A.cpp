#include<bits/stdc++.h>

using namespace std;


void solve(int t){
  string s;
  cin >> s;

  string rs = s;
  reverse(rs.begin(), rs.end());

  cout << rs + s << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
