#include<iostream>

using namespace std;


void solve(){

  int n;
  int a[10000], r[10000];
  cin >> n;
  for(int i=0; i < n; i++){
    cin >> a[i];
  }

  int s = 0;
  for(int i = 0; i < n; i++){
    int sc = 0;
    int x = a[i];
    int y = a[i+1];
    if(i == 0) y = a[0];
    while(1){
      sc++; 
      y = x % y;
      if(y == 0) break;
      x = y;
    }
    if(sc > s) s = sc;
  }
  cout << s;
}

int gcd(int a, int b){
  // if(b > a) { int t = a; a = b; b = t; }
  // if(b == 0) return a;
  // return gcd(b, a%b);
  while(1){
    b = a % b;
    if(b == 0) return a;
    a = b;
  }
}


int main(){
  cout << gcd(54, 24);
  // int t;
  // cin >> t;
  // while(t--)
  //   solve();
  // return 0; 
}
