#include <iostream>

using namespace std;

void solve(){
  int n;
  cin >> n;
  int c = 1;
  while(1){
    if(c*c >= n) {
      cout << n << endl;
      return;
    }
  }
}

int main(){
  int t;
  cin >> t;
  while(t--)
    solve();
  return 0;
}
