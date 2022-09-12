#include<bits/stdc++.h>


using namespace std;


void solve(int t){
  int n;
  cin >> n;

  string ts;
  cin >> ts;

  string s = "";
  for(int i = n-1; i >= 0; i--){
    if(ts[i] == '0') {
      int cc = 0;
      for(int j = i-2; j < i; j++){
	cc = cc * 10 + (ts[j]-'0');
      }

      s += ('a' + cc-1);

      i-= 2;
      continue;
    }

    s += ('a'+ (ts[i]-'0'-1));
  }  


  reverse(s.begin(), s.end());
  cout << s << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
