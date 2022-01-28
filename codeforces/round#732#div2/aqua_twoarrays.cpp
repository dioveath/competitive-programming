


#include <iostream>

using namespace std;

void solve(){

  int n, a[100], b[100];
  int asum = 0, bsum = 0;

  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> a[i];
    asum += a[i];
  }
  for(int i = 0; i < n; i++){
    cin >> b[i];
    bsum += b[i];
  }

  if(asum != bsum) {
    cout << -1 << endl;
    return;
  }

  int k = 0;
  int ij[100][2];
  for(int i = 0; i < n; i++){
    while(a[i] != b[i])
      if(a[i] > b[i]) {
	int j = 0; 
	while(j < n) {
	  if(a[j] < b[j]) break;
	  j++;
	}
	a[i]--;
	a[j]++;
	// NOTE: problem specified index starting from 1;
	ij[k][0] = i+1;
	ij[k][1] = j+1;
	k++;
      } else if(a[i] < b[i]){
	int j = 0;
	while(j < n) {
	  if(a[j] > b[j]) break;
	  j++;
	}
	a[i]++;
	a[j]--;
	ij[k][0] = j+1;
	ij[k][1] = i+1;	
	k++;
      }
  }
  cout << k << endl;
  for(int i = 0; i < k; i++)
    cout << ij[i][0] << " " << ij[i][1] << endl;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    solve();
  }
}
