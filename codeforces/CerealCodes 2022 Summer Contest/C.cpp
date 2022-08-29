#include<bits/stdc++.h>


using namespace std;


int main(){
  int T;
  cin >> T;


  while(--T){
    int n, k;
    cin >> n >> k;

    int ans = 0;
    while(n != 1 && k){

      bool found = false;
      for(int i = 2; i <= 6; i++){
	if(n % i == 0) {
	  ans += i;
	  k--;
	  n/=i;
	  found = true;
	  break;
	}
      }

      if(!found) {
	cout << -1 << endl;
	break;	
      }

    }

    while(k > 0) { ans++; k--; }

    cout << ((k < 0) ? -1 : ans) << endl;
  }

}
