#include<bits/stdc++.h>


using namespace std;


void solve(int t){

  int N, M;
  cin >> N >> M;

  int C[N];
  int nc = 0;
  for(int i = 0; i < N; i++) {
    cin >> C[i];
    nc += C[i];
  }

  cout << "Test #" << t << ": " << nc % M << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
