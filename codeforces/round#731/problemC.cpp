

#include<iostream>

using namespace std;

void solve(){
  int m, n, k;

  cin >> m >> n >> k;

  int[] mw = new int[100];
  for(int i =0; i < m;i++){
    cin >> mw[i];
  }

  int[] r = new int[200];

  int[] nw = new int[100];
  int p = mw[0];
  int j= 0;
  for(int i =0; i < n;i++){
    cin >> nw[i];
    if(p >= nw[i]) {
      r[j++] = nw[i];
      r[j++] = p;
    }else {
      r[j++] = p;      
      r[j++] = nw[i];
    }
    p = nw[i];
  }

  for(int k = 0; i < j; i++){
    cout >> r[i];
  }
}

int main(){
  int t = 0;
  cin >> t;
  for(int i = 0; i < t;i++){
    solve();
  }


  return 0;
}
