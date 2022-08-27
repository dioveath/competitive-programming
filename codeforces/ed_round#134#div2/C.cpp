#include<bits/stdc++.h>


using namespace std;


void solve(int t){
  int n;
  cin >> n;

  vector<int> a(n, 0), b(n, 0);
  for(int i = 0; i < n; i++)
    cin >> a[i];
  for(int i = 0; i < n; i++)
    cin >> b[i];

  vector<int> d(n, 0);
  unordered_map<int, int> umap;

  for(int i = 0; i < n; i++){
    if(umap[a[i]]) {
      vector<int> t(n, 0);
      // for(int j = 0; j < n; j++)
      // umap.remove(a[i]);
    }
  }


}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
