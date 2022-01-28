#include <iostream>


using namespace std;

void solve(){
  int n;
  cin >> n;
  int a[2*n];
  for(int i = 0; i < 2*n; i++){
    cin >> a[i];
  }

  // int x[n];
  // int y[n];
  // int k = 0;
  int res = true;
  int p = false;
  for(int i = 0; i < 2*n; i++){
    if(a[i] == -1) continue;
    for(int j = i+1; j < 2*n; j++){
      if(a[j] == -1) continue;
      if((a[i] + a[j]) % 2 == 1) {
	// x[k] = a[i]; y[k++] = a[j];
	a[i] = -1; a[j] = -1;
	p = true;
	break;
      }
    }
    if(p) {
      p = false;
      continue;
    }
    else {
      res = false;
      break;
    }
  }

  // for(int i = 0; i < k; i++){
  //   cout << x[i] << " ";
  // }
  // cout << endl;
  // for(int i = 0; i < k; i++){
  //   cout << y[i] << " ";
  // }

  if(res) cout << "yes" << endl;
  else
    cout << "no" << endl;
}

int main(){

  int t = 0;
  cin >> t;
  for(int i = 0; i < t; i++){
    solve();
  }

}
