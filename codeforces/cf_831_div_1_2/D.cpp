#include<bits/stdc++.h>

using namespace std;

void solve(int t){
  int m, n, k;
  cin >> m >> n >> k;

  vector<int> cards;
  for(int i = 0; i < k; i++) {
    int a;
    cin >> a;
    cards.push_back(a);
  }

  for(int i = 0; i < k; i++){
    if(cards[i]+1 < (m+n-1)) {
      cout << "TIDAK" << endl;
      return;
    }
  }

  cout << "YA" << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}

