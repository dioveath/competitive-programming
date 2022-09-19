#include<bits/stdc++.h>

using namespace std;


void solve(int t){
  int n, k;
  cin >> n >> k;

  vector<long long> v(n);
  unordered_map<int, long long> um;
  for(int i = 0; i < n; i++) {
    cin >> v[i];
    if(um.find(i%k) != um.end()) {
      um[i%k] = max(um[i%k], v[i]);
    } else {
      um[i%k] = v[i];
    }
  }

  long long max_sum = 0;
  int i = 0;

  while(i < k){
    max_sum += um[i%k];
    i++;
  }

  long long cur_sum = max_sum;
  while(i < n){
    cur_sum -= um[(i-k)%k];
    cur_sum += um[i%k];

    if(cur_sum > max_sum) max_sum = cur_sum;
    i++;
  }

  cout << max_sum << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
