#include<bits/stdc++.h>

using namespace std;


void solve(int notneed){
    int n, t;
    cin >> n;
    cin >> t;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];    

    int ans = -1;
    for(int i = 0; i < n; i++){
        if(a[i] <= t && (ans == -1 || b[i] > b[ans])) ans = i;
        t--;
    }

    cout << (ans == -1 ? -1 : ans+1) << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
