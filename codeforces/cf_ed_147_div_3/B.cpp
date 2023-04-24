#include<bits/stdc++.h>

using namespace std;


void solve(int notneed){
    int n;
    cin >> n;

    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    cout << max(a[0] * a[1], a[n-1] * a[n-2]) << endl; 
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
