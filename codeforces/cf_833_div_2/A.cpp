#include<bits/stdc++.h>

using namespace std;


void solve(int t){
  int n;
  cin >> n;
  cout << n/2 + (n%2==0?0:1) << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
