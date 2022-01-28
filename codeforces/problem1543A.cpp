#include <iostream>

using namespace std;


int gcd(int a, int b){
  while(b){
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

void solve(){
  int a, b;
  cin >> a >> b;

  if(a > b) {
    int t = a; a = b; b = t;
  }

  int e = b - a;
  int s = 0;
  int la = a;
  int lb = b;
  int ra = a;
  int rb = b;
  while(e != 0) {
    if(gcd(la, lb) == e) break;
    if(gcd(ra, rb) == e) break;
    la--,lb--,ra++,rb++;
    s++;
  }

  cout << e << " " << s << endl;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    solve();
  }
}
