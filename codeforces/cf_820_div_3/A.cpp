#include<bits/stdc++.h>


using namespace std;


void solve(int t){
  int a, b, c;
  cin >> a >> b >> c;

  if(a == 1)  {
    cout << 1 << endl;
    return;
  }

  int t2 = 0;
  if(c > b){
    t2 = (c-b)*2 + b;
  } else t2 = b;

  if(t2 == a) cout << 3 << endl;
  else if(t2 > a) cout << 1 << endl;
  else cout << 2 << endl;

}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}

