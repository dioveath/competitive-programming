
#include <iostream>


using namespace std;


void solve(){
  
  int n, H;
  cin >> n >> H;
  int a[n];


  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      if(a[i] < a[j]) {
	int temp = a[j];
	a[j] = a[i];
	a[i] = temp;
      }
    }
  }

  int pv = a[0];
  H -= a[0];
  int c = 1;
  for(int i = 0;i < n && H > 0; i++){
    if(H > 0 && pv != a[i]) {
      H -= a[i];
      i = 0;
      c++;
    }
  }

  cout << c << endl;
}



int main(){

  int T;
  cin >> T;

  while(T--){
    solve();
  }

  return 0;
}
