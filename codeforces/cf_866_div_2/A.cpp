#include<bits/stdc++.h>

using namespace std;


void solve(int t){
    string s;
    cin >> s;

    int n = s.length();

    int ans = s[0] == '_';
    for(int i = 0; i < n; i++){
        if(s[i] == '_' && (i+1 < n && s[i+1] != '^')) {
            ans++;
        }
    }
    ans += (s[n-1] == '_');

    if(n == 1) ans = (s[0] == '^' ? 1 : 2);
    cout << ans << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
