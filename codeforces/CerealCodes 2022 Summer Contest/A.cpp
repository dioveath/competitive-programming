#include<bits/stdc++.h>


using namespace std;


int main(){
  int n;
  cin >> n;

  vector<int> a(n, 0);

  for(int i = 0; i < n; i++) 
    cin >> a[i];

  sort(a.begin(), a.end());

  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans += (n-i);
    while(i+1 < n && a[i] == a[i+1]) i++;
  }

  cout << ans << endl;
}
