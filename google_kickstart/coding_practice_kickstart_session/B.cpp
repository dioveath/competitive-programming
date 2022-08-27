#include<bits/stdc++.h>


using namespace std;


void solve(int t){
  long N;
  cin >> N;

  long V[N];
  for(long i = 0; i < N; i++) cin >> V[i];

  long rbd = 0;
  long max_v = 0;

  for(long i = 0; i < N; i++) {
    if((i == 0 || V[i] > max_v) &&
       ((i+1) == N || V[i] > V[i+1])) {
      rbd++;
    }
    if(V[i] > max_v) max_v = V[i];
  }

  cout << "Case #" << t << ": " << rbd << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
