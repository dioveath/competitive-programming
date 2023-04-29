#include<bits/stdc++.h>

// NOTE: NOT SOLVED
using namespace std;

void solve(int t){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 1; i <= n; i++) a[i-1] = i;

    vector<int> fact(n+1);
    fact[1] = 1;
    for(int i = 2; i <= n+1; i++) fact[i] = fact[i-1] * i;

    int sum = fact[n];
    cout << sum << endl;
    if(sum % (n) != 0){
        for(int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
        return;
    }

    cout << "-1" << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
