#include<bits/stdc++.h>


using namespace std;


void solve(int t){
  int N;
  cin >> N;

  int A[N], B[N];
  for(int i = 0; i < N; i++)
    cin >> A[i] >> B[i];

  int P;
  cin >> P;

  int C[P];
  for(int i = 0; i < P; i++)
    cin >> C[i];

  cout << "Case #" << t << ": ";
  for(int i = 0; i < P; i++){
    int bus = 0;
    for(int j = 0; j < N; j++){
      if(C[i] >= A[j] && C[i] <= B[j]) bus++;
    }
    cout << bus << " ";
  }

  cout << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
