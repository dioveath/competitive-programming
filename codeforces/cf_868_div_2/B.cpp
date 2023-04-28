#include<bits/stdc++.h>

using namespace std;

void solve(int t){
    int n, k;
    cin >> n >> k;

    

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int change = 0;
    for(int i = 0; i < n; i++){
        if(abs(a[i] - (i+1)) % k != 0) change++;
            }

    if(change == 0) {
        cout << 0 << endl;
    } else if(change <= 2) {
        cout << 1 << endl;
    } else {
        cout << -1 << endl;
    }
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
