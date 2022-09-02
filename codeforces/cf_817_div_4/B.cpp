#include<bits/stdc++.h>


using namespace std;


void solve(int t){
  int n;
  cin >> n;
  string grid, grid2;
  cin >> grid >> grid2;


  for(int i = 0; i < n; i++){
    if(grid[i] == 'R' && grid2[i] != 'R') {
      cout << "NO" << endl;
      return;
    }

    if(grid2[i] == 'R' && grid[i] != 'R') {
      cout << "NO" << endl;
      return;
    }    
  }

  cout << "YES" << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
