#include<bits/stdc++.h>

using namespace std;
int gcd(int a, int b){
  if(b > a) swap(a, b);
  while(b){
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}


void solve(int t){
  int n;
  cin >> n;

  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }

  int max = -1;
  for(int i = v.size()-1; i >= 0; i--){
    for(int j = i; j >= 0; j--){
      if(gcd(v[i], v[j]) == 1 && (i+j+2) > max) {
	max = i+j+2;
      }      
    }
  }

  cout << max << endl;
}


int main(){
  int T;
  cin >> T;
  for(int i = 0; i < T; i++)
    solve(i+1);
}
