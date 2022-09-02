#include<bits/stdc++.h>


using namespace std;


void solve(int t){
  int n;
  cin >> n;

  int a[n], b[n];

  for(int i = 0; i < n; i++)
    cin >> a[i];
  for(int i = 0; i < n; i++)
    cin >> b[i];


  for(int i = 0; i < n; i++){
    if(a[i] == b[i]) continue;
    if(a[i] > b[i]) {
      cout << "NO" << endl;
      return;
    }

    if((i+1 < n && a[i] > a[i+1]) ||
       (i == n-1 && a[i] > a[0])) {
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
