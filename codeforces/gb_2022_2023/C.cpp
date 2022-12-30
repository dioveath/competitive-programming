#include<bits/stdc++.h>

using namespace std;

void solve(int t){
  int n;
  cin >> n;

  vector<int> a(n);
  for(int i = 0;i < n; i++)
    cin >> a[i];

  // if exists gcd(a[i] + x, a[j] + x) = 1 for all 1 <= i,j <= n
  // if not cout << "NO";
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i == j) continue;
      if(a[i] % 2 == 0 && a[j] % 2 == 0 || a[i] == a[j]) {
	cout << "NO" << endl;
	return;
      }
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
