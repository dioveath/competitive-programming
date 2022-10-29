#include<bits/stdc++.h>

using namespace std;

void solve(int t){
  int n;
  cin >> n;

  vector<pair<int, int>> r;
  for(int i = 0; i < n; i++){
    int a, b;
    cin >> a >> b;
    if(a > b) swap(a, b);
    r.push_back({a, b});
  }

  

  

}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
