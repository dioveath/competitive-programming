#include<bits/stdc++.h>


using namespace std;


void solve(int t){
  int n, k, r, c;
  cin >> n >> k >> r >> c;

  char m[n][n];

  m[r-1][c-1] = 'X';
  

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i == 0 && j == k-1) {
	m[i][j] = 'X';
	continue;
      }

      if(i == 0 && j % (k-1) == 0) {
	m[i][j] = 'X';
	continue;
      }

      if(j == 0 && i % (k-1) == 0) {
	m[i][j] = 'X';
	continue;
      }
    }
  }


  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(m[i][j] == 'X') cout << 'X';
      else cout << '.';
    }
    cout << endl;
  }
  

}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
