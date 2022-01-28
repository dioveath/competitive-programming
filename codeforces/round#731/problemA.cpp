#include<iostream>

using namespace std;

void solve();

int main(){
  int t;
  cin >> t;
  int a[t];
  for(int i = 0; i < t; i++){
    solve();
  }
  return 0;
}


void solve(){
  int x1, y1, x2, y2, x3, y3, d = 0;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  if(x1 == x3 && x2 == x3 && ((y3 > y1 && y3 < y2) || (y3 > y2 && y3 < y1))) d += 2;
  if(y1 == y3 && y2 == y3 && ((x3 > x1 && x3 < x2) || (x3 > x2 && x3 < x1))) d += 2;
  d += x2 > x1 ? (x2 - x1) : x1 - x2;
  d += y2 > y1 ? (y2 - y1) : y1 - y2;
  cout << d << endl;
}
