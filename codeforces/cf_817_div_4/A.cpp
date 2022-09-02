#include<bits/stdc++.h>


using namespace std;


void solve(int t){
  int n;
  string str;
  cin >> n >> str;

  if(str.length() < 5) {
    cout << "NO" << endl;
    return;
  }

  unordered_map<char, int> umap({
      {'T', 1},
      {'i', 1},
      {'m', 1},
      {'u', 1},
      {'r', 1}
    });
  

  for(int i = 0; i < n; i++)  {
    if(umap[str[i]]) {
      umap.erase(str[i]);
    } else {
      cout << "NO" << endl;
      return;
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
