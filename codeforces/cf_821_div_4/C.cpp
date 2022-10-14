#include<bits/stdc++.h>

using namespace std;


void solve(int t){
  vector<vector<char>> A = vector<vector<char>>(8, vector<char>(8));
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      cin >> A[i][j];
    }
  }

  for(int i = 0; i < 8; i++){
    bool hort = true, vert = true;
    for(int j = 0; j < 8; j++){
      if(A[i][j] != 'R') {
	hort = false;
	break;
      }
    }

    if(hort) {
      cout << 'R' << endl;
      return;
    }

    for(int j = 0; j < 8; j++){
      if(A[j][i] != 'B') {
	vert = false;
	break;
      }
    }

    if(vert) {
      cout << 'B' << endl;
      return;
    }
  }
}


int main(){
  int T;
  cin >> T;
  for(int i = 0; i < T; i++)
    solve(i+1);
}
