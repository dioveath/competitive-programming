#include<bits/stdc++.h>

using namespace std;

// int gcd(int a, int b){
//   if(a > b) swap(a, b);
//   while(a > 0) {
//     int t = a;
//     a = b % a;
//     b = t;
//   }
//   return b;
// }


void solve(int t){
  long A, B, N, K;
  cin >> A >> B >> N >> K;

  long wd = 0;
  for(long i = 1; i <= N; i++){
    for(long j = 1; j <= N; j++){
      if(i == j) continue;
      if((lround(pow(i, A)) % K == 0) ||
	 (lround(pow(j, B)) % K == 0)) wd++;
    }
  }

  cout << "Test #" << t << ": " << wd << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}

