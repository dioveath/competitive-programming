#include<bits/stdc++.h>

using namespace std;


void solve(int t){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  int total = 0;
  for(int i = 0; i < n; i++){
    int csum = a[i];
    if(csum >= 0) total += csum;
    else continue;

    for(int j = i+1; j < n; j++){
      csum += a[j];
      if(csum >= 0) total += csum;
      else break;
    }
  }

  cout << "Case #" << t << ": " << total << endl;  
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
