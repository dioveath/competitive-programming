
#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;


void solve(){
  int n;
  cin >> n;

  vector<int> a;
  a.resize(n);

  int sc[100000][2];
  for(int i = 0; i < n; i++){
    cin >> a[i];
    ++sc[a[i]][i%2];
  }

  std::sort(a.begin(), a.end());

  for(int i = 0; i < n; i++){
    --sc[a[i]][i%2];
  }

  for(int i = 0; i < n; i++){
    if(sc[a[i]][0] != 0 || sc[a[i]][1] != 0) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;

  // int k = 0;
  // for(int j = 0; j < n; j++) { 
  //   for(int i = 0; i < n-j; i++){
  //     if(i == n-j-1) break;
  //     if(a[i] > a[i+1]) {
  // 	// auto itr = swapmap.find(a[i]);
  // 	// auto itr2 = swapmap.find(a[i+1]);

  // 	// if(itr != swapmap.end()){
  // 	//   itr->second++;
  // 	// } else {
  // 	//   swapmap.insert(pair<int, int>(a[i], 1));
  // 	// }
  // 	// if(itr2 != swapmap.end()){
  // 	//   itr2->second++;
  // 	// } else {
  // 	//   swapmap.insert(pair<int, int>(a[i+1], 1));
  // 	// }	

  // 	sc[a[i]][0]++;
  // 	sc[a[i+1]][0]++;	

  // 	int t = a[i];
  // 	a[i] = a[i+1];
  // 	a[i+1] = t;

  // 	k++;
  // 	// swapc[i]++;
  // 	// swapc[i+1]++;
  // 	// t = swapc[i];
  // 	// swapc[i] = swapc[i+1];
  // 	// swapc[i+1] = t;
  //     }
  //   }

  // }

  // for(int i = 0; i < n; i++){
  //   if(sc[a[i]][0] % 2 != 0){
  //     cout  << "NO" << endl; return;
  //   }
  // }
  // cout << "YES" << endl;

  // for(auto itr = swapmap.begin(); itr != swapmap.end(); itr++){
  //   cout << itr->first << ": " << itr->second << " ";
  // }
  // cout << endl;

  // for(int i =0; i< n; i++){
    // cout << swapc[i] << " ";
    // if(swapc[i] % 2 != 0) {
    //   cout << "NO" <<endl;
    //   return;
    // } 
  // }
  // cout << endl;


  // cout << "YES" << endl;
  // cout << "STEP: " << k << endl;
  // cout <<  a[i] << ", " << a[i+1] << endl;
  // if(k % 2 == 0) cout << "NO" << endl;
  // else cout << "YES" << endl;
}


int main(){
  int t;
  cin >> t;
  while(t--){
    solve();
  }
}
