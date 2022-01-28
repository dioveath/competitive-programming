

#include <iostream>

using namespace std;


void solve(){
  
  string s;
  cin >> s;

  char sc = s[0];
  // for(int i = 1; s.length(); i++){
    // if((int)s[i] < (int)sc) sc = s[i];
    // cout << s[i] << endl;
  // }

  cout << s.length() << endl;

}

int main(){
  int T;
  cin >> T;

  while(T--){
    solve();
  }

  return 0;
}
