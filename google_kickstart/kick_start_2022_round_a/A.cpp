#include<bits/stdc++.h>


using namespace std;


void solve(int t){
  string I, P;
  cin >> I >> P;

  int j = 0, i = 0, dc = 0;
  while(i < P.length()){
    if(j >= I.length()) {
      dc += (P.length() - i);
      break;
    }
    if(I[j] == P[i]) j++;
    else dc++;
    i++;
  }

  if(j >= I.length()) {
    cout << "Case #" << t << ": " << dc << endl;
  } else {
    cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;    
  }
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
