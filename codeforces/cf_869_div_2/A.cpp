#include<bits/stdc++.h>

// NOTE: SOLVED
using namespace std;

void solve(int t){
    int n, k;
    cin >> n >> k;

    vector<string> op(n);
    for(int i = 0; i < n; i++){
        cin >> op[i];
    }

    int ans = n;
    set<int> s;
    for(int j = 0; j < k; j++){
        char ch = op[0][j];
        int currentAns = 1;        
        for(int i = 1; i < n; i++){
            if(s.find(i) != s.end()) continue;
            if(op[i][j] == ch) currentAns++;
            else s.insert(i);
        }
        ans = min(ans, currentAns);
    }
    
    cout << ans << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
