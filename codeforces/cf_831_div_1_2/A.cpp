#include<bits/stdc++.h>

using namespace std;

void solve(int t){
  int n;
  cin >> n;

  if((n+2) % 2 == 0){
    cout << 2 << endl;
  }

  if((n+3) % 2 == 0) {
    cout << 3 << endl;
  }  

}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
