#include<bits/stdc++.h>

using namespace std;


void solve(int t){
  int n, x;
  cin >> n >> x;

  set<int> a({x});
  for(int i = 1; i < n; i++){
    if(a.size() == n-1) break;

    for(int j = 1; j < n; j++){
      if(a.find(j) != a.end()) continue;
      if(i % j == 0) {
	a.insert(j);
	break;
      }
    }
  }

  a.insert(1);

  if(a.size() != n) {
    cout << -1 << endl;
    return;
  }

  for(auto i : a)
    cout << i << " ";
  cout << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
